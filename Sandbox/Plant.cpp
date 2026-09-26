#include "Plant.h"

#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Texture.h>
#include <OldCat/Math/Rect.h>


Plant::Plant(std::string name, OldCat::GameContext& context, OldCat::Transform transform)
	: OldCat::Object(std::move(name), context, transform)
{
	addComponent<OldCat::SpriteComponent>(
		context.assetManager().loadTexture("assets/images/plant_256.png"),
		OldCat::Rect(
			OldCat::Vector2(-128.0f, -128.0f),
			OldCat::Vector2(256.0f, 256.0f)
		)
	);
}

void Plant::update()
{
	
}