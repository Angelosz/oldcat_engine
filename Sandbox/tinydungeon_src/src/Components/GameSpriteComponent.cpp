#include "GameSpriteComponent.h"
#include "../Constants.h"

namespace TinyDungeon
{
	GameSpriteComponent::GameSpriteComponent(OldCat::Object& object, OldCat::Texture& texture)
		: OldCat::SpriteComponent(
			object,
			texture,
			OldCat::Rect(
				OldCat::Vector2(-(CellSize / 2), -(CellSize / 2)),
				OldCat::Vector2(CellSize, CellSize)
			)) { }
}