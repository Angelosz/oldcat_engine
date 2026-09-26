#pragma once

#include <OldCat/UI/Widget.h>

#include <string>

namespace OldCat
{
	class Font;

	class Text : public Widget
	{
	public:
		Text(
			GameContext& context,
			Vector2 position,
			Font& font,
			std::string text
		);

		void update() override;
		void render() override;

		void setText(std::string text);
		const std::string& text() const;

	private:
		Font& m_font;
		std::string m_text;
	};
}