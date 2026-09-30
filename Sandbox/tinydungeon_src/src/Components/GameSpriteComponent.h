#pragma once

#include <OldCat/Components/SpriteComponent.h>

namespace TinyDungeon
{
	class GameSpriteComponent : public OldCat::SpriteComponent
	{
	public:
		GameSpriteComponent(OldCat::Object& object, OldCat::Texture& texture);
	};
}