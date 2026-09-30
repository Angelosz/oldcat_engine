#pragma once
#include <OldCat/World/Object.h>

namespace TinyDungeon
{

	class Cell;
	class GamePiece;

	class GameTable : public OldCat::Object
	{
	public:
		GameTable(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
			int nColumns, int nRows
			);

		void update(float deltaTime) override;

		void addCell(Cell& cell);
		void addEnvironmentPiece(GamePiece& piece);
		void addEnemyPiece(GamePiece& piece);
		void addPlayer(GamePiece& piece);

		Cell* cellAt(int column, int row);
		const Cell* cellAt(int column, int row) const;

		GamePiece* pieceAt(int column, int row);
		const GamePiece* pieceAt(int column, int row) const;

		int columns() const;
		int rows() const;

	private:
		int m_columns;
		int m_rows;

		std::vector<Cell*> m_cells;
		std::vector<GamePiece*> m_environment;
		std::vector<GamePiece*> m_enemies;
		GamePiece* m_player = nullptr;

		bool indexIsInBounds(int x, int y) const;
	};
}