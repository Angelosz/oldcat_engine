#pragma once

#include "Cell.h"
#include "GamePiece.h"
#include "GameTable.h"

namespace OldCat
{
	class GameContext;
	class World;
}

namespace TinyDungeon
{
	class DungeonFactory
	{
	public:
		DungeonFactory(OldCat::GameContext& gameContext, OldCat::World& world);

		GameTable& setupDungeon(std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);

	private:
		OldCat::GameContext& m_context;
		OldCat::World& m_world;

		void createCells(GameTable& gameTable, std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);
		void createGamePieces(GameTable& gameTable, std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);
	};
}