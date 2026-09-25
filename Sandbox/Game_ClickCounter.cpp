#include "Game_ClickCounter.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>

#include <iostream>
#include <string>

Game_ClickCounter::Game_ClickCounter(OldCat::GameContext& gameContext)
	: OldCat::Game(gameContext)
	, m_font("assets/fonts/PressStart2P-Regular.ttf", 32.0f)
	, m_backgroundTexture(gameContext.assetManager().loadTexture("assets/images/Background_720_1280.png"))
{
	spawn<OldCat::SpriteObject>("Background", context(), "assets/images/Background_720_1280.png", OldCat::Rect(0.0f, 0.0f, 720.0f, 1280.0f));

	m_plant = &spawn<Plant>("Plant", context());
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

	renderer().drawText(
		m_font,
		text.c_str(),
		540.0f / 2.0f - (static_cast<float>(text.length()) * 32.0f) / 2.0f, 32.0f
	);
}