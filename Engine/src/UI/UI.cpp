#include <OldCat/UI/UI.h>

namespace OldCat
{
	UI::UI(GameContext& gameContext) : m_context(gameContext) { }

	void UI::update(float deltaTime)
	{
		for (auto& widget : m_widgets)
		{
			widget->update(deltaTime);
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