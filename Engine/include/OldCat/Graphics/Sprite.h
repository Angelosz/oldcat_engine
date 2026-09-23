#pragma once

#include <string>

namespace OldCat
{
	class Sprite
	{
	public:
		Sprite(
			const char* path,
			int xPosition,
			int yPosition,
			float width,
			float hight
		);

		const char* path();
		int xPosition();
		int yPosition();

	private:
		const char* m_texturePath;
		int m_xPosition;
		int m_yPosition;
	};
}