#pragma once

#include "Cell.h"

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

		Cell* createCell(std::string type, OldCat::Transform trasnform);

	private:
		OldCat::GameContext& m_context;
		OldCat::World& m_world;
	};
}