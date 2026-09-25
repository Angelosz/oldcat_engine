#include <OldCat/World/SpriteObject.h>

#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Texture.h>
#include <OldCat/Math/Rect.h>

namespace OldCat
{
	SpriteObject::SpriteObject(std::string name, OldCat::GameContext& context, Transform transform,
		const char* path, OldCat::Rect rect)
		: OldCat::Object(std::move(name), context, transform)
	{
		m_spriteComponent = &addComponent<OldCat::SpriteComponent>(
			context.assetManager().loadTexture(path),
			rect
		);
	}

	void SpriteObject::update() { }
}