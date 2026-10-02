#include <OldCat/World/World.h>
#include <OldCat/Core/GameContext.h>

#include <utility>
#include <algorithm>
#include <OldCat/Components/RenderComponent.h>

namespace OldCat
{
	World::World(GameContext& gameContext)
		: m_context(gameContext) { }

	void World::update(float deltaTime)
	{
		for (auto& object : m_objects)
		{
			if(object->isActive()) object->update(deltaTime);
		}
	}

	void World::render()
	{
		for (const auto& object : m_objects)
		{
			if (!object->isVisible() || !object->isActive()) continue;

			for (const auto& component : object->getComponents())
			{
				if (auto* render = dynamic_cast<RenderComponent*>(component.get()))
				{
					 render->render(m_context.renderer());
				}
			}
		}
	}

	void World::destroy(Object& object)
	{
		const auto it = std::find_if(
			m_objects.begin(),
			m_objects.end(),
			[&object](const std::unique_ptr<Object>& ptr)
			{
				return ptr.get() == &object;
			}
		);

		if (it == m_objects.end())
			return;

		const auto pendingIt = std::find(
			m_pendingDestroy.begin(),
			m_pendingDestroy.end(),
			&object
		);

		if (pendingIt != m_pendingDestroy.end())
			return;

		m_pendingDestroy.push_back(&object);
	}

	void World::flushDestroyedObjects()
	{
		if (m_pendingDestroy.empty())
			return;

		std::erase_if(
			m_objects,
			[this](const std::unique_ptr<Object>& object)
			{
				return std::find(
					m_pendingDestroy.begin(),
					m_pendingDestroy.end(),
					object.get()
				) != m_pendingDestroy.end();
			}
		);

		m_pendingDestroy.clear();
	}
}