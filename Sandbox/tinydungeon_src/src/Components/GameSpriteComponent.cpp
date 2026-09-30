#include "GameSpriteComponent.h"

GameSpriteComponent::GameSpriteComponent(OldCat::Object& object, OldCat::Texture& texture)
	: OldCat::SpriteComponent(
		object,
		texture,
		OldCat::Rect(
			OldCat::Vector2(-16.0f, -16.0f),
			OldCat::Vector2(32.0f, 32.0f)
		)) { }