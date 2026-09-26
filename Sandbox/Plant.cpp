#include "Plant.h"

#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Texture.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Components/ColliderComponent.h>

#include <iostream>

using OldCat::ColliderComponent;
using OldCat::Vector2;
using OldCat::Rect;

Plant::Plant(std::string name, OldCat::GameContext& context, OldCat::Transform transform)
	: OldCat::Object(std::move(name), context, transform)
{
	Rect spriteSize = Rect(
		Vector2(-128.0f, -128.0f),
		Vector2(256.0f, 256.0f)
	);

	addComponent<OldCat::SpriteComponent>(
		assetManager().loadTexture("assets/images/plant_256.png"),
		spriteSize
	);

	addComponent<ColliderComponent>(
		spriteSize
	);
}

void Plant::update(float deltaTime)
{
	if (const auto* collider = getComponent<OldCat::ColliderComponent>())
	{
		if (collider->wasClicked(input()))
		{
			events().clicked();
		}
	}
}