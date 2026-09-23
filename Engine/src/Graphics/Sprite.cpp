#include <OldCat/Graphics/Sprite.h>

namespace OldCat
{
	Sprite::Sprite(const std::string texturePath, int xPosition, int yPosition, float width, float hight)
		: m_texturePath(texturePath), m_xPosition(xPosition), m_yPosition(yPosition) {
	}

	int Sprite::xPosition()
	{
		return m_xPosition;
	}

	int Sprite::yPosition()
	{
		return m_yPosition;
	}
}
