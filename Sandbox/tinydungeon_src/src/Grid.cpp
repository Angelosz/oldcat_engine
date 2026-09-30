#include "Grid.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/World/Transform.h>

namespace TinyDungeon
{
	Grid::Grid(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		DungeonFactory& dungeonFactory, int columns, int rows, float cellSize, const std::vector<std::string>& cells)
		: OldCat::Object(name, gameContext, transform)
		, m_dungeonFactory(dungeonFactory), m_columns(columns), m_rows(rows), m_cellSize(cellSize)
	{
		m_cells.clear();
		m_cells.reserve(static_cast<size_t>(columns * rows));

		for (int row = 0; row < m_rows; ++row)
		{
			for (int column = 0; column < m_columns; ++column)
			{
				int index = row * m_columns + column;

				m_cells.push_back(
					m_dungeonFactory.createCell(
						cells[index],
						OldCat::Transform{
							OldCat::Vector2{
								transform.y() + (column - (m_columns - 1) / 2.0f) * m_cellSize,
								transform.x() + (row - (m_rows - 1) / 2.0f) * m_cellSize
							}
						}
					)
				);
			}
		}
	}

	void Grid::update(float deltaTime) {}
}