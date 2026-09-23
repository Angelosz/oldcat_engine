#pragma once

#include <string>

namespace OldCat
{
	class Sprite
	{
	public:
		Sprite(
			const std::string path,
			int xPosition,
			int yPosition,
			float width,
			float height
		);

		int xPosition();
		int yPosition();

	private:
		std::string m_texturePath;
		int m_xPosition;
		int m_yPosition;
		int width;
		int height;
	};
}