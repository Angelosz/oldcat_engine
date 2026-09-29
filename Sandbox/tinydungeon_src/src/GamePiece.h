#pragma once
#include <OldCat/World/Object.h>
#include "PieceType.h"

class GamePiece : public OldCat::Object
{
public:
	GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		const char* texturePath, PieceType pieceType
	);

	void update(float deltaTime) override;
};