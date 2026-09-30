#include "Game_ClickCounter.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>
#include <OldCat/World/Transform.h>

#include <string>
#include <iostream>

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;

Game_ClickCounter::Game_ClickCounter(OldCat::GameContext& gameContext) : OldCat::Game(gameContext)
	, m_font("assets/fonts/PressStart2P-Regular.ttf", 32.0f)
{
	spawn<OldCat::SpriteObject>(
		"Background",
		context(),
		Transform{ Vector2(0.0f, 0.0f) },
		"assets/images/Background_720_1280.png",
		Rect(
			Vector2(0.0f, 0.0f),
			Vector2(720.0f, 1280.0f)
		)
	);

	m_plant = &spawn<Plant>(
		"Plant",
		context(),
		Transform{ Vector2(360.0f, 1024.0f) }
	);

	m_plant->events().onClicked(
		[this]()
		{
			increaseCounter();
		}
	);

	m_clicksText = &addWidget<OldCat::Text>(
		Vector2{ 32.0f, 32.0f },
		m_font,
		"Clicks: 0"
	);
}

void Game_ClickCounter::increaseCounter()
{
	++m_counter;

	m_clicksText->setText("Clicks: " + std::to_string(m_counter));
}

void Game_ClickCounter::update(float deltaTime) {
	if (input().wasKeyPressed(OldCat::Key::Up))
	{
		std::cout << "Up was Pressed!" << '\n';
	}
	if (input().wasKeyPressed(OldCat::Key::Down))
	{
		std::cout << "Down was Pressed!" << '\n';
	}
	if (input().wasKeyPressed(OldCat::Key::Left))
	{
		std::cout << "Left was Pressed!" << '\n';
	}
	if (input().wasKeyPressed(OldCat::Key::Right))
	{
		std::cout << "Right was Pressed!" << '\n';
	}

	if (input().wasMouseButtonPressed(OldCat::MouseButton::Left))
	{
		std::cout << "Left Click!" << '\n';
	}
	if (input().wasMouseButtonPressed(OldCat::MouseButton::Middle))
	{
		std::cout << "Middle Click!" << '\n';
	}
	if (input().wasMouseButtonPressed(OldCat::MouseButton::Right))
	{
		std::cout << "Right Click!" << '\n';
	}

}

void Game_ClickCounter::render() {}
