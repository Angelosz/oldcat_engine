#pragma once

#include <OldCat/Math/Rect.h>

#include <string>

namespace OldCat
{
	class Texture;

	class Sprite
	{
	public:
		Sprite(
			Texture& texture,
			Rect rect
		);

		Texture& texture();
		Rect& rect();

	private:
		Texture& m_texture;
		Rect m_rect;
	};
}