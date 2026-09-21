#include "Game_ClickCounter.h"
#include <OldCat/Input.h>
#include <OldCat/Renderer.h>
#include <OldCat/AssetManager.h>
#include <OldCat/Font.h>

#include <iostream>
#include <string>

Game_ClickCounter::Game_ClickCounter(OldCat::AssetManager& assetManager)
	: m_font("assets/fonts/PressStart2P-Regular.ttf", 32.0f)
	, m_buttonTexture(assetManager.loadTexture("assets/images/plant_256.png"))
{
}

void Game_ClickCounter::update(const OldCat::Input& input)
{
	if (input.wasMouseButtonPressed(OldCat::MouseButton::Left))
	{
		++m_counter;
	}
}

void Game_ClickCounter::render(OldCat::Renderer& renderer)
{
	std::string text = "Clicks: " + std::to_string(m_counter);

	renderer.drawText(
		m_font,
		text.c_str(),
		540/2 - (static_cast<float>(text.length()) * 32.0f) / 2.0f, 32
	);

	renderer.drawTexture(
		m_buttonTexture,
		540/2 - 256/2, 960/2 + 256/2
	);
}
