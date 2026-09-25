#include <OldCat/Graphics/Sprite.h>

namespace OldCat
{
	Sprite::Sprite(Texture& texture, Rect rect)
		: m_texture(texture), m_rect(rect)
	{ }

	Texture& Sprite::texture()
	{
		return m_texture;
	}

	Rect& Sprite::rect()
	{
		return m_rect;
	}
}