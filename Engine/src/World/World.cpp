#include <OldCat/World/World.h>
#include <OldCat/Core/GameContext.h>

#include <utility>
#include <OldCat/Components/RenderComponent.h>

namespace OldCat
{
	World::World(GameContext& gameContext)
		: m_context(gameContext) { }

	void World::update()
	{
		for (auto& object : m_objects)
		{
			object->update();
		}
	}

	void World::render()
	{
		for (const auto& object : m_objects)
		{
			for (const auto& component : object->getComponents())
			{
				if (auto* render = dynamic_cast<RenderComponent*>(component.get()))
				{
					render->render(m_context.renderer());
				}
			}
		}
	}
}