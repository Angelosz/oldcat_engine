#include <OldCat/UI/Widget.h>

#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Widget::Widget(GameContext& gameContext, Vector2 position) : m_context(gameContext), m_position(position) { }

	GameContext& Widget::context()
	{
		return m_context;
	}

	Vector2 Widget::position()
	{
		return m_position;
	}

	const Vector2 Widget::position() const
	{
		return m_position;
	}

	Renderer& Widget::renderer()
	{
		return m_context.renderer();
	}

	Input& Widget::input()
	{
		return m_context.input();
	}

	AssetManager& Widget::assetManager()
	{
		return m_context.assetManager();
	}
}