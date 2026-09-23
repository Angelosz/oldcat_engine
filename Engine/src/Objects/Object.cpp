#include <OldCat/Objects/Object.h>
#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Object::Object(std::string name, GameContext& context)
		: m_name(name), m_context(context){ }

	GameContext& Object::context()
	{
		return m_context;
	}

	Renderer& Object::renderer()
	{
		return m_context.renderer();
	}

	Input& Object::input()
	{
		return m_context.input();
	}

	AssetManager& Object::assetManager()
	{
		return m_context.assetManager();
	}

}