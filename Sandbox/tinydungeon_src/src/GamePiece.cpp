#include "GamePiece.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/World/Transform.h>

GamePiece::GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
	const char* texturePath, PieceType pieceType
)	: OldCat::Object(name, gameContext, transform)
{ }

void GamePiece::update(float deltaTime) { }
