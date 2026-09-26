#include <OldCat/UI/Text.h>
#include <OldCat/Graphics/Renderer.h>

#include <utility>

namespace OldCat
{
	Text::Text(GameContext& gameContext, Vector2 position, Font& font, std::string text)
		: OldCat::Widget(gameContext, position), m_font(font), m_text(std::move(text)) { }

	void Text::update() { }

	void Text::render()
	{
		renderer().drawText(
			m_font,
			m_text.c_str(),
			position().x,
			position().y
		);
	}

	void Text::setText(std::string text)
	{
		m_text = std::move(text);
	}

	const std::string& Text::text() const
	{
		return m_text;
	}
}