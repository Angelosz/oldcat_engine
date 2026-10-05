#include "GamePiece.h"
#include "GamePiece.h"
#include "GamePiece.h"

#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/World/Transform.h>

namespace TinyDungeon
{
	GamePiece::GamePiece(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		const char* texturePath, PieceType pieceType, OldCat::Vector2 position
	) : OldCat::Object(name, gameContext, transform), m_type(pieceType), m_position(position)
	{
		m_sprite = &addComponent<GameSpriteComponent>(
			assetManager().loadTexture(texturePath)
		);
	}

	void GamePiece::update(float deltaTime) {}

	OldCat::Vector2 GamePiece::position()
	{
		return m_position;
	}

	void GamePiece::updatePosition(OldCat::Vector2 newPosition)
	{
		m_position = newPosition;
	}

	PieceType TinyDungeon::GamePiece::pieceType()
	{
		return m_type;
	}
	bool TinyDungeon::GamePiece::canEnterCell(CellType cellType) const
	{
		switch (m_type)
		{
		case PieceType::Player:
			return cellType == CellType::Floor;

		case PieceType::Enemy:
			return cellType == CellType::Floor ||
				cellType == CellType::Water;

		default:
			return false;
		}
	}
	bool TinyDungeon::GamePiece::canInteractWithGamePiece(PieceType pieceType) const
	{
		switch (m_type)
		{
		case PieceType::Player:
			return pieceType == PieceType::Gold ||
				pieceType == PieceType::Door ||
				pieceType == PieceType::Enemy;

		case PieceType::Enemy:
			return pieceType == PieceType::Player;

		default:
			return false;
		}
	}

	GameSpriteComponent& TinyDungeon::GamePiece::spriteComponent()
	{
		return *m_sprite;
	}
}