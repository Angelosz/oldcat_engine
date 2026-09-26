#include <OldCat/Components/SpriteComponent.h>
#include <OldCat/Graphics/Renderer.h>
#include <OldCat/World/Object.h>
#include <OldCat/World/Transform.h>

namespace OldCat
{
	SpriteComponent::SpriteComponent(Object& object, Texture& texture, Rect rect)
		: OldCat::RenderComponent(object), m_sprite(texture, rect) { }

	void SpriteComponent::render(Renderer& renderer)
	{
		const Rect& rect = m_sprite.rect();
		const Transform& transform = owner().transform();

		renderer.drawTexture(
			m_sprite.texture(),
			transform.x() + rect.x(),
			transform.y() + rect.y()
		);
	}

	Sprite& SpriteComponent::sprite()
	{
		return m_sprite;
	}
}