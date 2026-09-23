#include "Plant.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Graphics/Renderer.h>

#include <utility>

Plant::Plant(std::string name, OldCat::GameContext& context, OldCat::Sprite sprite)
	: OldCat::Object(std::move(name), context), m_sprite(sprite)
{ }

void Plant::update() { }

