#include <OldCat/UI/UI.h>

namespace OldCat
{
	UI::UI(GameContext& gameContext) : m_context(gameContext) { }

	void UI::update()
	{
		for (auto& widget : m_widgets)
		{
			widget->update();
		}
	}

	void UI::render()
	{
		for (auto& widget : m_widgets)
		{
			widget->render();
		}
	}
}