#include <OldCat/Graphics/Sprite.h>

namespace OldCat
{
	Sprite::Sprite(Texture& texture, Rect rect)
		: m_texture(&texture), m_rect(rect)
	{ }

	const Texture& Sprite::texture() const
	{
		return *m_texture;
	}

	const Rect& Sprite::rect() const
	{
		return m_rect;
	}

	void Sprite::setTexture(Texture& texture)
	{
		m_texture = &texture;
	}
}