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
		const Rect& rect() const;

	private:
		Texture& m_texture;
		Rect m_rect;
	};
}