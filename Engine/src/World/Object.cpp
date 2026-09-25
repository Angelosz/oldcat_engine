#include <OldCat/World/Object.h>
#include <OldCat/Core/GameContext.h>

#include <string>
#include <vector>
#include <memory>

namespace OldCat
{
	Object::Object(std::string name, GameContext& context)
		: m_name(name), m_context(context){ }

	const std::vector<std::unique_ptr<Component>>& Object::getComponents() const
	{
		return m_components;
	}

	GameContext& Object::context()
	{
		return m_context;
	}

	const std::string& Object::name() const
	{
		return m_name;
	}
}