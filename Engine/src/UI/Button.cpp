#include <OldCat/UI/Button.h>

#include <OldCat/Input/Input.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Renderer.h>

namespace OldCat
{
	Button::Button(GameContext& context, Rect bounds,
		std::function<void()> onClick, const char* texture)
		: Widget(context, bounds)
		, m_onClick(onClick)
		, m_background(assetManager().loadTexture(texture), bounds)
	{ }

	void Button::update(float deltaTime)
	{
		if (input().wasMouseButtonPressed(MouseButton::Left))
		{
			Vector2 mousePosition = input().mousePosition();

			if (bounds().contains(mousePosition))
			{
				if (m_onClick)
				{
					m_onClick();
				}
			}
		}
	}

	void Button::render()
	{
		renderer().drawSprite(m_background);
	}

	void Button::setOnClick(std::function<void()> onClick)
	{
		m_onClick = onClick;
	}
}