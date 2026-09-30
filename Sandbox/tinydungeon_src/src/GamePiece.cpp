#include "GamePiece.h"

#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/World/Transform.h>

namespace TinyDungeon
{
	GamePiece::GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		const char* texturePath, PieceType pieceType
	) : OldCat::Object(name, gameContext, transform), m_type(pieceType)
	{
		m_sprite = &addComponent<GameSpriteComponent>(
			assetManager().loadTexture(texturePath)
		);
	}

	void GamePiece::update(float deltaTime) {}
}