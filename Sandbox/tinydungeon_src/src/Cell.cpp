#include "Cell.h"

#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/World/Transform.h>


namespace TinyDungeon
{
	Cell::Cell(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		const char* texturePath, CellType cellType, OldCat::Vector2 position)
		: OldCat::Object(name, gameContext, transform)
		, m_type(cellType), m_sprite(nullptr), m_gamePiece(nullptr), m_position(position)
	{
		m_sprite = &addComponent<GameSpriteComponent>(
			assetManager().loadTexture(texturePath)
		);
	}

	void Cell::update(float deltaTime) { }

	CellType& Cell::cellType()
	{
		return m_type;
	}

	const OldCat::Vector2 Cell::position() const
	{
		return m_position;
	}

	OldCat::SpriteComponent& Cell::sprite()
	{
		return *m_sprite;
	}

	GamePiece* Cell::gamePiece()
	{
		return m_gamePiece;
	}

	const GamePiece* Cell::gamePiece() const
	{
		return m_gamePiece;
	}

	void Cell::setGamePiece(GamePiece* gamePiece)
	{
		m_gamePiece = gamePiece;
	}

	bool Cell::isOccupied() const
	{
		return m_gamePiece != nullptr;
	}

}