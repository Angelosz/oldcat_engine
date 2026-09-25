#include "Plant.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Graphics/Renderer.h>

#include <utility>
#include <iostream>

Plant::Plant(std::string name, OldCat::GameContext& context, OldCat::Sprite sprite)
	: OldCat::Object(std::move(name), context), m_sprite(sprite)
{ }

void Plant::update()
{
	
}

OldCat::Sprite& Plant::sprite()
{
	return m_sprite;
}