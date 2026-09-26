#pragma once

#include <OldCat/Math/Vector2.h>

namespace OldCat
{
	class Rect
	{
	public:
		Rect(Vector2 position, Vector2 size);

		float x() const;
		float y() const;
		float width() const;
		float height() const;

		const Vector2 position() const;
		const Vector2 size() const;

		bool contains(Vector2 point) const;

	private:
		Vector2 m_position;
		Vector2 m_size;
	};
}