#include "Game_ClickCounter.h"

#include <OldCat/GameContext.h>
#include <OldCat/AssetManager.h>
#include <OldCat/Input.h>
#include <OldCat/Renderer.h>

#include <iostream>
#include <string>

Game_ClickCounter::Game_ClickCounter(OldCat::GameContext& gameContext)
	: OldCat::Game(gameContext)
	, m_font("assets/fonts/PressStart2P-Regular.ttf", 32.0f)
	, m_backgroundTexture(gameContext.assetManager().loadTexture("assets/images/Background_720_1280.png"))
	, m_plantTexture(gameContext.assetManager().loadTexture("assets/images/plant_256.png"))
{
}

void Game_ClickCounter::update()
{
	if (input().wasMouseButtonPressed(OldCat::MouseButton::Left))
	{
		++m_counter;
	}
}

void Game_ClickCounter::render()
{
	std::string text = "Clicks: " + std::to_string(m_counter);

	renderer().drawTexture(
		m_backgroundTexture,
		0, 0
	);

	renderer().drawTexture(
		m_plantTexture,
		(720/2) - (256 / 2),
		(1280/2) + 256
	);

	renderer().drawText(
		m_font,
		text.c_str(),
		540 / 2 - (static_cast<float>(text.length()) * 32.0f) / 2.0f, 32
	);
}
