#include "Game_TinyDungeon.h"

#include <OldCat/Input/Input.h>
#include <OldCat/World/Transform.h>

#include "src/Constants.h"
#include "src/GameTable.h"

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;
using OldCat::Key;

namespace TinyDungeon
{
	Game_TinyDungeon::Game_TinyDungeon(OldCat::GameContext& gameContext) : OldCat::Game(gameContext)
		, m_font("assets/fonts/PressStart2P-Regular.ttf", 12.0f), m_dungeonFactory(gameContext, world())
		, m_randomGenerator(std::random_device{}())
	{
		std::vector<std::string> m_grid{
			"W", "W",	"W",	 "W",	"W",	"W",
			"W", "F_G", "F_F",	 "F_F",	"F_F",	"W",
			"W", "F_F", "F_F",	 "F_F",	"F_P",	"W",
			"W", "F_F", "F_E01", "F_F", "F_F",	"W",
			"W", "F_F", "F_D01", "F_F", "F_F",	"W",
			"W", "W",	"W",	 "W",	"W",	"W",
		};

		int nRows = 6;
		int nColumns = 6;

		m_table = &m_dungeonFactory.setupDungeon(m_grid, nRows, nColumns, CellSize);

		m_goldCollectedText = &addWidget<OldCat::Text>(
			Vector2{ 12.0f, 12.0f },
			m_font,
			"Gold Collected: 0 / 1"
		);

		m_gameState = GameState::PlayerTurn;
	}

	void Game_TinyDungeon::update(float deltaTime)
	{
		if (m_gameState == GameState::PlayerTurn)
		{
			if (input().wasKeyPressed(Key::Up))
			{
				if (m_table != nullptr)
				{
					if (movePlayer(0, -1))
					{
						playEnemyTurn();
					}
				}
			}
			if (input().wasKeyPressed(Key::Down))
			{
				if (m_table != nullptr)
				{
					if (movePlayer(0, 1))
					{
						playEnemyTurn();
					}
				}
			}
			if (input().wasKeyPressed(Key::Left))
			{
				if (m_table != nullptr)
				{
					if (movePlayer(-1, 0))
					{
						playEnemyTurn();
					}
				}
			}
			if (input().wasKeyPressed(Key::Right))
			{
				if (m_table != nullptr)
				{
					if (movePlayer(1, 0))
					{
						playEnemyTurn();
					}
				}
			}
		}
	}


	void Game_TinyDungeon::render() {}

	bool Game_TinyDungeon::movePlayer(int xDirection, int yDirection)
	{
		GamePiece* player = m_table->playerPiece();
		Vector2 playerPosition = player->position();

		Cell* playerCell = m_table->cellAt(
			playerPosition.x,
			playerPosition.y
		);

		Cell* targetCell = m_table->cellAt(
			playerPosition.x + xDirection,
			playerPosition.y + yDirection
		);

		if (targetCell == nullptr)
			return false;

		if (targetCell->isOccupied())
		{
			GamePiece* targetGamePiece = targetCell->gamePiece();

			if (!player->canInteractWithGamePiece(targetGamePiece->pieceType()))
				return false;

			resolveInteraction(player, targetGamePiece);

			if (targetCell->isOccupied())
				return false;
		}

		if (player->canEnterCell(targetCell->cellType()))
		{
			m_table->movePiece(playerCell, targetCell);
			
			return true;
		}

		return false;
	}

	void Game_TinyDungeon::resolveInteraction(GamePiece* player, GamePiece* targetGamePiece)
	{
		switch (targetGamePiece->pieceType())
		{
		case PieceType::Gold:
			m_goldCollected++;
			m_goldCollectedText->setText("Gold Collected: " + std::to_string(m_goldCollected) + " / 1");

			targetGamePiece->setIsActive(false);

			m_table->removeGamePiece(targetGamePiece);

			destroy(*targetGamePiece);
			break;

		case PieceType::Door:
			// Lo implementaremos cuando hagamos la victoria.
			break;

		case PieceType::Enemy:
			// Lo implementaremos cuando hagamos el Game Over.
			break;

		case PieceType::Player:
			// Lo usará el enemigo cuando implementemos su turno.
			break;
		}
	}

	void Game_TinyDungeon::playEnemyTurn()
	{
		m_gameState = GameState::EnemyTurn;

		std::uniform_int_distribution<int> directionDistribution(0, 3);

		for (GamePiece* enemy : m_table->enemies())
		{
			int direction = directionDistribution(m_randomGenerator);

			switch (direction)
			{
			case 0:
				moveEnemy(enemy, Vector2(0, -1));
				break;
			case 1:
				moveEnemy(enemy, Vector2(0, 1));
				break;
			case 2:
				moveEnemy(enemy, Vector2(-1, 0));
				break;
			case 3:
				moveEnemy(enemy, Vector2(1, 0));
				break;
			}
		}

		if (m_gameState != GameState::Ended)
		{
			m_gameState = GameState::PlayerTurn;
		}
	}

	void Game_TinyDungeon::moveEnemy(GamePiece* enemy, Vector2 direction)
	{
		Vector2 enemyPosition = enemy->position();
		Vector2 newPosition(
			enemyPosition.x + direction.x,
			enemyPosition.y + direction.y
		);

		Cell* targetCell = m_table->cellAt(newPosition.x, newPosition.y);

		if (targetCell == nullptr) return;

		if (enemy->canEnterCell(targetCell->cellType()))
		{
			if (!targetCell->isOccupied())
			{
				m_table->movePiece(enemyPosition, newPosition);
			}
			else
			{
				if (targetCell->gamePiece()->pieceType() == PieceType::Player)
				{
					m_table->movePiece(enemyPosition, newPosition);
					gameOver();
				}
			}
		}
	}

	void Game_TinyDungeon::gameOver()
	{
		m_gameState = GameState::Ended;
	}
}
