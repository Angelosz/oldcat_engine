#include "Game_TinyDungeon.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>
#include <OldCat/World/Transform.h>
#include <OldCat/UI/Text.h>

#include "src/Constants.h"

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;

namespace TinyDungeon
{
	Game_TinyDungeon::Game_TinyDungeon(OldCat::GameContext& gameContext) : OldCat::Game(gameContext)
		, m_font("assets/fonts/PressStart2P-Regular.ttf", 12.0f), m_dungeonFactory(gameContext, world())
	{
		std::vector<std::string> grid{
			"W", "W",	"W",	 "W",	"W",	"W",
			"W", "F_G", "F_F",	 "F_F",	"F_F",	"W",
			"W", "F_F", "F_F",	 "F_F",	"F_P",	"W",
			"W", "F_F", "F_E01", "F_F", "F_F",	"W",
			"W", "F_F", "F_D01", "F_F", "F_F",	"W",
			"W", "W",	"W",	 "W",	"W",	"W",
		};

		int nRows = 6;
		int nColumns = 6;

		m_table = &m_dungeonFactory.setupDungeon(grid, nRows, nColumns, CellSize);

		&addWidget<OldCat::Text>(
			Vector2{ 12.0f, 12.0f },
			m_font,
			"Gold Collected: 0 / 1"
		);
	}

	void Game_TinyDungeon::update(float deltaTime) {}
	void Game_TinyDungeon::render() {}


}
