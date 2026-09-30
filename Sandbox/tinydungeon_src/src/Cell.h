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
			const char* texturePath, CellType cellType);

		void update(float deltaTime) override;

		CellType& cellType();
		OldCat::SpriteComponent& sprite();

		GamePiece* gamePiece();
		const GamePiece* gamePiece() const;

		void setGamePiece(GamePiece* piece);

	private:
		CellType m_type;
		GameSpriteComponent* m_sprite;

		GamePiece* m_gamePiece = nullptr;
	};
}
