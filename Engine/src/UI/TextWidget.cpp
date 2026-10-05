#include <OldCat/UI/TextWidget.h>
#include <OldCat/Graphics/Renderer.h>

#include <utility>

namespace OldCat
{
	TextWidget::TextWidget(GameContext& gameContext, Rect bounds, Text text)
		: OldCat::Widget(gameContext, bounds), m_text(std::move(text)) { }

	void TextWidget::update(float deltaTime) { }

	void TextWidget::render()
	{
		renderer().drawText(
			m_text.font,
			m_text.content.c_str(),
			bounds().position().x,
			bounds().position().y
		);
	}

	void TextWidget::setText(std::string text)
	{
		m_text.content = text;
	}
}