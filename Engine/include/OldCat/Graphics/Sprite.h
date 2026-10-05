#pragma once

#include <OldCat/Math/Rect.h>

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

		const Texture& texture() const;
		const Rect& rect() const;

		void setTexture(Texture& texture);

	private:
		Texture* m_texture;
		Rect m_rect;
	};
}