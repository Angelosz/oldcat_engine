#pragma once

#include <OldCat/UI/Widget.h>
#include <OldCat/UI/Text.h>

#include <string>

namespace OldCat
{
	class Font;

	class TextWidget : public Widget
	{
	public:
		TextWidget(
			GameContext& context,
			Rect bounds,
			Text text
		);

		void update(float deltaTime) override;
		void render() override;

		void setText(std::string text);

	private:
		Text m_text;
	};
}