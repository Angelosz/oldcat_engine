#pragma once
#include <OldCat/World/Object.h>

#include "Cell.h"
#include "GamePiece.h"
#include "GameTable.h"

#include <string>
#include <vector>

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

		GameTable& setupDungeon(const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);

	private:
		OldCat::GameContext& m_context;
		OldCat::World& m_world;

		void createCells(GameTable& gameTable, const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);
		void createGamePieces(GameTable& gameTable, const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize);
	};
}