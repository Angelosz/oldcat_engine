#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Graphics/Renderer.h>

namespace OldCat
{
	SpriteComponent::SpriteComponent(Object& object, Texture& texture, Rect rect)
		: OldCat::RenderComponent(object), m_sprite(texture, rect) { }

	void SpriteComponent::render(Renderer& renderer)
	{
		const Rect& rect = m_sprite.rect();

		renderer.drawTexture(
			m_sprite.texture(),
			rect.x(),
			rect.y()
		);
	}

	Sprite& SpriteComponent::sprite()
	{
		return m_sprite;
	}
}