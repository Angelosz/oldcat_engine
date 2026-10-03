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
		return x >= 0 && y >= 0 && x < m_columns && y < m_rows;
	}

	void GameTable::assignGamePieceToCell(GamePiece& gamePiece)
	{
		int cellIndex = static_cast<int>(gamePiece.position().y) * m_columns + static_cast<int>(gamePiece.position().x);

		m_cells[cellIndex]->setGamePiece(&gamePiece);
	}

	void GameTable::addCell(Cell& cell)
	{
		m_cells.push_back(&cell);
	}

	void GameTable::addEnvironmentPiece(GamePiece& gamePiece)
	{
		m_environment.push_back(&gamePiece);

		assignGamePieceToCell(gamePiece);
	}

	void GameTable::addEnemyPiece(GamePiece& gamePiece)
	{
		m_enemies.push_back(&gamePiece);

		assignGamePieceToCell(gamePiece);
	}

	void GameTable::addPlayer(GamePiece& gamePiece)
	{
		m_player = &gamePiece;

		assignGamePieceToCell(gamePiece);
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

	GamePiece* GameTable::playerPiece()
	{
		return m_player;
	}

	std::vector<GamePiece*>& GameTable::enemies()
	{
		return m_enemies;
	}

	int GameTable::columns() const
	{
		return m_columns;
	}

	int GameTable::rows() const
	{
		return m_rows;
	}

	void GameTable::movePiece(OldCat::Vector2 from, OldCat::Vector2 to)
	{
		Cell* fromCell = cellAt(
			static_cast<int>(from.x),
			static_cast<int>(from.y)
		);

		Cell* toCell = cellAt(
			static_cast<int>(to.x),
			static_cast<int>(to.y)
		);

		if (fromCell == nullptr || toCell == nullptr)
		{
			return;
		}

		movePiece(fromCell, toCell);
	}

	void GameTable::movePiece(Cell* from, Cell* to)
	{
		GamePiece* piece = from->gamePiece();

		if (piece != nullptr)
		{
			from->setGamePiece(nullptr);
			to->setGamePiece(piece);

			piece->transform().position = to->transform().position;
			piece->updatePosition(to->position());
		}
	}

	void GameTable::removeGamePiece(GamePiece* gamePiece)
	{
		if (gamePiece != nullptr)
		{
			OldCat::Vector2 position = gamePiece->position();
			Cell* cell = cellAt(position.x, position.y);

			cell->setGamePiece(nullptr);

			std::erase(m_environment, gamePiece);
			std::erase(m_enemies, gamePiece);
		}
	}
}