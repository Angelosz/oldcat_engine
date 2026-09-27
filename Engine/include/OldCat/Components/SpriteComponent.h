#pragma once

#include <OldCat/Components/RenderComponent.h>
#include <OldCat/Graphics/Sprite.h>

namespace OldCat
{
	class Object;
	class Renderer;
	class Texture;

	class SpriteComponent : public OldCat::RenderComponent
	{
	public:
		explicit SpriteComponent(
			OldCat::Object& object,
			Texture& texture,
			Rect rect
		);

		void render(OldCat::Renderer& renderer) override;

		Sprite& sprite();

	private:
		Sprite m_sprite;
	};
}