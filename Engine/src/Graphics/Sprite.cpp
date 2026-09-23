#include <OldCat/Graphics/Sprite.h>

namespace OldCat
{
	Sprite::Sprite(Texture& texture, int xPosition, int yPosition, float width, float height)
		: m_texture(texture), m_xPosition(xPosition), m_yPosition(yPosition),
		m_width(width), m_height(height)
	{ }

	int Sprite::xPosition()
	{
		return m_xPosition;
	}

	int Sprite::yPosition()
	{
		return m_yPosition;
	}

	int Sprite::width()
	{
		return m_width;
	}

	int Sprite::height()
	{
		return m_height;
	}
}
