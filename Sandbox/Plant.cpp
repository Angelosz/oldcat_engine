#include "Plant.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Graphics/Sprite.h>
#include <OldCat/Graphics/Texture.h>


Plant::Plant(std::string name, OldCat::GameContext& context, OldCat::Sprite sprite)
	: OldCat::Object(name, context), m_sprite(sprite)
{ }

/*void Plant::render()
{
	OldCat::Texture plantTexture = assetManager().loadTexture(m_sprite.path());

	renderer().drawTexture(
		plantTexture,
		m_sprite.xPosition(),
		m_sprite.yPosition()
	);
}*/

void Plant::update() { }

