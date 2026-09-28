#pragma once
#include <OldCat/World/Object.h>
#include "DungeonFactory.h"
#include "Cell.h"

class Grid : public OldCat::Object
{
public:
	Grid(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		DungeonFactory& dungeonFactory, int columns, int rows, float cellSize, const std::vector<std::string>& cells);

	void update(float deltaTime) override;

private:
	DungeonFactory& m_dungeonFactory;
	int m_columns;
	int m_rows;
	float m_cellSize;

	std::vector<Cell*> m_cells;
};