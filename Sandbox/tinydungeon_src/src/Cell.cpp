#include "Cell.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/World/Transform.h>

Cell::Cell(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
	const char* texturePath, CellType cellType)
: OldCat::Object(name, gameContext, transform), m_type(cellType)
{
	m_sprite = &addComponent<OldCat::SpriteComponent>(
		assetManager().loadTexture(texturePath),
		OldCat::Rect(
			OldCat::Vector2( -16.0f, -16.0f ),
			OldCat::Vector2( 32.0f, 32.0f )
		)
	);
}

void Cell::update(float deltaTime) { }

CellType& Cell::cellType()
{
	return m_type;
}

OldCat::SpriteComponent& Cell::sprite()
{
	return *m_sprite;
}