#include "Plant.h"

#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Texture.h>
#include <OldCat/Math/Rect.h>



Plant::Plant(std::string name, OldCat::GameContext& context)
	: OldCat::Object(std::move(name), context)
{
	addComponent<OldCat::SpriteComponent>(
		context.assetManager().loadTexture("assets/images/plant_256.png"),
		OldCat::Rect(
			(720 / 2) - (256 / 2),
			(1280 / 2) + 256,
			256.0f,
			256.0f
		)
	);
}

void Plant::update()
{
	
}