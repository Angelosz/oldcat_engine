#pragma once

#include <OldCat/World/Object.h>
#include "CellType.h"
#include "Components/GameSpriteComponent.h"

namespace TinyDungeon
{
	class GamePiece;

	class Cell : public OldCat::Object
	{
	public:
		Cell(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
			const char* texturePath, CellType cellType, OldCat::Vector2 position);

		void update(float deltaTime) override;

		CellType& cellType();
		const OldCat::Vector2 position() const;
		OldCat::SpriteComponent& sprite();

		GamePiece* gamePiece();
		const GamePiece* gamePiece() const;

		void setGamePiece(GamePiece* piece);

		bool isOccupied() const;

	private:
		CellType m_type;
		OldCat::Vector2 m_position;

		GameSpriteComponent* m_sprite;

		GamePiece* m_gamePiece = nullptr;
	};
}
