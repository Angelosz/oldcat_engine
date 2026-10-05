#pragma once
#include <OldCat/World/Object.h>

#include <vector>

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
		void addDoor(GamePiece& piece);

		Cell* cellAt(int column, int row);
		const Cell* cellAt(int column, int row) const;

		GamePiece* pieceAt(int column, int row);
		const GamePiece* pieceAt(int column, int row) const;

		GamePiece* playerPiece();
		std::vector<GamePiece*>& enemies();
		GamePiece* doorPiece();

		int columns() const;
		int rows() const;

		void movePiece(OldCat::Vector2 from, OldCat::Vector2 to);
		void movePiece(Cell* from, Cell* to);
		
		void removeGamePiece(GamePiece* gamePiece);

	private:
		int m_columns;
		int m_rows;

		std::vector<Cell*> m_cells;
		std::vector<GamePiece*> m_environment;
		std::vector<GamePiece*> m_enemies;
		GamePiece* m_player = nullptr;
		GamePiece* m_door = nullptr;

		bool indexIsInBounds(int x, int y) const;
		void assignGamePieceToCell(GamePiece& gamePiece);
	};
}