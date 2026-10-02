#pragma once
#include <OldCat/World/Object.h>

#include "PieceType.h"
#include "CellType.h"
#include "Components/GameSpriteComponent.h"

namespace TinyDungeon
{
	class GamePiece : public OldCat::Object
	{
	public:
		GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
			const char* texturePath, PieceType pieceType, OldCat::Vector2 position
		);

		void update(float deltaTime) override;

		OldCat::Vector2 position();
		void updatePosition(OldCat::Vector2 newPosition);

		PieceType pieceType();

		bool canEnterCell(CellType cellType) const;
		bool canInteractWithGamePiece(PieceType pieceType) const;

	private:
		OldCat::Vector2 m_position;

		GameSpriteComponent* m_sprite;
		PieceType m_type;
	};
}