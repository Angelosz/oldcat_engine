#pragma once
#include <OldCat/UI/Widget.h>
#include <OldCat/UI/Text.h>
#include <OldCat/Graphics/Sprite.h>

#include <functional>

namespace OldCat
{
	class Button : public Widget
	{
	public:
		explicit Button(GameContext& context, Rect bounds,
			std::function<void()> onClick = {},
			const char* texture = "assets/engine/T_ButtonBackground.png"
		);

		void update(float deltaTime) override;
		void render() override;

		void setOnClick(std::function<void()> onClick);

	private:
		std::function<void()> m_onClick;

		Sprite m_background;
	};
}