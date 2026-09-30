#include "GameTable.h"

#include "Cell.h"
#include "GamePiece.h"

namespace TinyDungeon
{
	GameTable::GameTable(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		int nColumns, int nRows)
		: OldCat::Object(name, gameContext, transform), m_columns(nColumns), m_rows(nRows)
	{
		m_cells.reserve(nColumns * nRows);
	}

	void GameTable::update(float deltaTime) { }

	bool GameTable::indexIsInBounds(int x, int y) const
	{
		return x > 0 && y > 0 && x < m_columns && y < m_rows;
	}

	void GameTable::addCell(Cell& cell)
	{
		m_cells.push_back(&cell);
	}

	void GameTable::addEnvironmentPiece(GamePiece& gamePiece)
	{
		m_environment.push_back(&gamePiece);
	}

	void GameTable::addEnemyPiece(GamePiece& gamePiece)
	{
		m_enemies.push_back(&gamePiece);
	}

	void GameTable::addPlayer(GamePiece& gamePiece)
	{
		m_enemies.push_back(&gamePiece);
	}

	Cell* GameTable::cellAt(int column, int row)
	{
		if (indexIsInBounds(column, row))
		{
			return m_cells[row * m_columns + column];
		}

		return nullptr;
	}

	const Cell* GameTable::cellAt(int column, int row) const
	{
		if (indexIsInBounds(column, row))
		{
			return m_cells[row * m_columns + column];
		}

		return nullptr;
	}

	GamePiece* GameTable::pieceAt(int column, int row)
	{
		if (indexIsInBounds(column, row))
		{
			return m_cells[row * m_columns + column]->gamePiece();
		}
		
		return nullptr;
	}

	const GamePiece* GameTable::pieceAt(int column, int row) const
	{
		if (indexIsInBounds(column, row))
		{
			return m_cells[row * m_columns + column]->gamePiece();
		}

		return nullptr;
	}

	int GameTable::columns() const
	{
		return m_columns;
	}

	int GameTable::rows() const
	{
		return m_rows;
	}
}