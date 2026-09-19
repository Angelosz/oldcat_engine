#include "Game_ClickCounter.h"
#include <OldCat/Input.h>
#include <OldCat/Renderer.h>
#include <OldCat/Font.h>

#include <iostream>
#include <string>

Game_ClickCounter::Game_ClickCounter()
	: m_font("assets/fonts/PressStart2P-Regular.ttf", 32.0f)
{
}

void Game_ClickCounter::update(const OldCat::Input& input)
{
	if (input.wasMouseButtonPressed(OldCat::MouseButton::Left))
	{
		++m_counter;

		std::cout << "Clicks: " << m_counter << '\n';
	}
}

void Game_ClickCounter::render(OldCat::Renderer& renderer)
{
	std::string text = "Clicks: " + std::to_string(m_counter);

	renderer.drawText(
		m_font,
		text.c_str(),
		20, 20);
}
