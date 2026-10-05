#pragma once

#include <OldCat/Core/Game.h>
#include <OldCat/Graphics/Font.h>
#include <OldCat/UI/TextWidget.h>

#include "src/DungeonFactory.h"
#include "src/GamePiece.h"
#include "src/GameState.h"

#include <random>

namespace TinyDungeon
{
	class Game_TinyDungeon : public OldCat::Game
	{
	public:
		explicit Game_TinyDungeon(OldCat::GameContext& gameContext);

		void update(float deltaTime) override;
		void render() override;

	private:
		OldCat::Font m_font;
		DungeonFactory m_dungeonFactory;
		std::mt19937 m_randomGenerator;

		std::vector<std::string> m_grid;
		GameTable* m_table = nullptr;
		int m_goldCollected = 0;
		OldCat::TextWidget* m_goldCollectedText = nullptr;

		GameState m_gameState = GameState::Setup;

		bool movePlayer(int xDirection, int yDirection);
		void resolveInteraction(GamePiece* player, GamePiece* gamePiece);

		void playEnemyTurn();
		void moveEnemy(GamePiece* enemy, OldCat::Vector2 direction);

		void gameOver();
	};
}