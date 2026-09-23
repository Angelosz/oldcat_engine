#include <OldCat/World/Object.h>
#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Object::Object(std::string name, GameContext& context)
		: m_name(name), m_context(context){ }

	GameContext& Object::context()
	{
		return m_context;
	}
}