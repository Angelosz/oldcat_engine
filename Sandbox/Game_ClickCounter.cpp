#include "Game_ClickCounter.h"
#include <OldCat/Input.h>

#include <iostream>

void Game_ClickCounter::update(const OldCat::Input& input)
{
	if (input.wasMouseButtonPressed(OldCat::MouseButton::Left))
	{
		++m_counter;

		std::cout << "Clicks: " << m_counter << '\n';
	}
}
