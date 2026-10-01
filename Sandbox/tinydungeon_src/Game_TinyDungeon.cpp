#include "Game_TinyDungeon.h"
#include "Game_TinyDungeon.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>
#include <OldCat/World/Transform.h>
#include <OldCat/UI/Text.h>

#include "src/Constants.h"
#include "src/GameTable.h"

#include <iostream>

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;
using OldCat::Key;

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

		m_goldCollectedText = &addWidget<OldCat::Text>(
			Vector2{ 12.0f, 12.0f },
			m_font,
			"Gold Collected: 0 / 1"
		);
	}

	void Game_TinyDungeon::update(float deltaTime)
	{
		if (input().wasKeyPressed(Key::Up))
		{
			if (m_table != nullptr)
			{
				movePlayer(0, -1);
			}
		}
		if (input().wasKeyPressed(Key::Down))
		{
			if (m_table != nullptr)
			{
				movePlayer(0, 1);
			}
		}
		if (input().wasKeyPressed(Key::Left))
		{
			if (m_table != nullptr)
			{
				movePlayer(-1, 0);
			}
		}
		if (input().wasKeyPressed(Key::Right))
		{
			if (m_table != nullptr)
			{
				movePlayer(1, 0);
			}
		}
	}


	void Game_TinyDungeon::render() {}

	void Game_TinyDungeon::movePlayer(int xDirection, int yDirection)
	{
		Vector2 playerPosition = m_table->playerPiece()->position();

		Cell* playerCell = m_table->cellAt(
			playerPosition.x,
			playerPosition.y
		);

		Cell* targetCell = m_table->cellAt(
			playerPosition.x + xDirection,
			playerPosition.y + yDirection
		);

		if (targetCell != nullptr) {
			CellType cellType = targetCell->cellType();

			if (cellType == CellType::Floor)
			{
				if (targetCell->isOccupied())
				{
					GamePiece* targetGamePiece = targetCell->gamePiece();

					if (targetGamePiece->pieceType() == PieceType::Gold)
					{
						m_goldCollected++;

						m_goldCollectedText->setText("Gold Collected: " + std::to_string(m_goldCollected) + " / 1");

						m_table->removeGamePiece(targetGamePiece);
					}
				}

				m_table->movePiece(playerCell, targetCell);
			}
		}
	}


}
