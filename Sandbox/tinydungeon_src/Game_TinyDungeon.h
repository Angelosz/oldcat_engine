#pragma once

#include <OldCat/Core/Game.h>
#include <OldCat/Graphics/Font.h>

#include "src/DungeonFactory.h"
#include "src/GamePiece.h"
#include <OldCat/UI/Text.h>

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

		GameTable* m_table = nullptr;
		int m_goldCollected = 0;
		OldCat::Text* m_goldCollectedText = nullptr;

		void movePlayer(int xDirection, int yDirection);
		//void playEnemiesTurn();
		//void playEnvironmentTurn();
	};
}