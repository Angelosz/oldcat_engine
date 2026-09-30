#pragma once
#include <OldCat/World/Object.h>

#include "PieceType.h"
#include "Components/GameSpriteComponent.h"

namespace TinyDungeon
{
	class GamePiece : public OldCat::Object
	{
	public:
		GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
			const char* texturePath, PieceType pieceType
		);

		void update(float deltaTime) override;

	private:
		GameSpriteComponent* m_sprite;
		PieceType m_type;
	};
}