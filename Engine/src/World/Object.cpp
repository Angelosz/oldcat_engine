#include <OldCat/World/Object.h>
#include <OldCat/Core/GameContext.h>

#include <string>
#include <vector>
#include <memory>

namespace OldCat
{
	Object::Object(std::string name, GameContext& context, Transform transform)
		: m_name(name), m_context(context), m_transform(transform) { }

	void Object::setIsActive(bool isActive)
	{
		m_isActive = isActive;
	}

	void Object::setVisibility(bool isVisible)
	{
		m_isVisible = isVisible;
	}
	
	bool Object::isActive() const
	{
		return m_isActive;
	}

	bool Object::isVisible() const
	{
		return m_isVisible;
	}

	EventDispatcher& Object::events()
	{
		return m_events;
	}

	const std::string& Object::name() const
	{
		return m_name;
	}

	Transform& Object::transform()
	{
		return m_transform;
	}

	const Transform& Object::transform() const
	{
		return m_transform;
	}

	const std::vector<std::unique_ptr<Component>>& Object::getComponents() const
	{
		return m_components;
	}

	GameContext& Object::context()
	{
		return m_context;
	}

	AssetManager& Object::assetManager()
	{
		return m_context.assetManager();
	}

	Input& Object::input()
	{
		return m_context.input();
	}

	Renderer& Object::renderer()
	{
		return m_context.renderer();
	}
}