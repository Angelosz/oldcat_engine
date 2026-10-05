#include <OldCat/UI/Widget.h>

#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Widget::Widget(GameContext& gameContext, Rect bounds)
		: m_context(gameContext), m_bounds(bounds) { }

	GameContext& Widget::context()
	{
		return m_context;
	}

	Vector2 Widget::position()
	{
		return m_bounds.position();
	}

	const Vector2 Widget::position() const
	{
		return m_bounds.position();
	}

	Rect Widget::bounds()
	{
		return m_bounds;
	}

	const Rect Widget::bounds() const
	{
		return m_bounds;
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