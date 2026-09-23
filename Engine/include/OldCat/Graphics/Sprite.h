#pragma once

#include <string>

namespace OldCat
{
	class Texture;

	class Sprite
	{
	public:
		Sprite(
			Texture& texture,
			int xPosition,
			int yPosition,
			float width,
			float height
		);

		int xPosition();
		int yPosition();
		int width();
		int height();

	private:
		Texture& m_texture;
		int m_xPosition;
		int m_yPosition;
		int m_width;
		int m_height;
	};
}