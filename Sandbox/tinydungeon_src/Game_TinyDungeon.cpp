#include "Game_TinyDungeon.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>
#include <OldCat/World/Transform.h>
#include "src/Grid.h"
#include <OldCat/UI/Text.h>

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;

Game_TinyDungeon::Game_TinyDungeon(OldCat::GameContext& gameContext) : OldCat::Game(gameContext)
, m_font("assets/fonts/PressStart2P-Regular.ttf", 12.0f), m_dungeonFactory(gameContext, world())
{
	spawn<Grid>(
		"Grid",
		context(),
		Transform{ Vector2(256.0f, 256.0f) },
		m_dungeonFactory,
		6, 6, 32.0f,
		std::vector<std::string>{
			"W", "W", "W", "W", "W", "W",
			"W", "F_G", "F_E", "F_E", "F_E", "W",
			"W", "F_E", "F_E", "F_E", "F_P", "W",
			"W", "F_E", "F_S", "F_E", "F_E", "W",
			"W", "F_E", "F_D", "F_E", "F_E", "W",
			"W", "W", "W", "W", "W", "W",
		/*"W", "W", "W", "W", "W", "W","W", "W", "W", "W", "W", "W", "W", "W", "W", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "F", "F", "F", "F", "F","F", "F", "F", "F", "F", "F", "F", "F", "F", "W",
		"W", "W", "W", "W", "W", "W","W", "W", "W", "W", "W", "W", "W", "W", "W", "W",*/
	});

	&addWidget<OldCat::Text>(
		Vector2{ 12.0f, 12.0f },
		m_font,
		"Gold Collected: 0 / 1"
	);
}

void Game_TinyDungeon::update(float deltaTime) { }
void Game_TinyDungeon::render() { }