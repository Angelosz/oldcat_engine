#include <OldCat/Math/Rect.h>
#include "Widget.h"

namespace OldCat
{
	Rect::Rect(Vector2 position, Vector2 size)
		: m_position(position), m_size(size)
	{ }

	bool Rect::contains(Vector2 point) const
	{
		return point.x >= m_position.x
			&& point.x <= m_position.x + m_size.x
			&& point.y >= m_position.y
			&& point.y <= m_position.y + m_size.y;
	}

	const Vector2 Rect::position() const
	{
		return m_position;
	}

	const Vector2 Rect::size() const
	{
		return m_size;
	}


	float Rect::x() const
	{
		return m_position.x;
	}

	float Rect::y() const
	{
		return m_position.y;
	}

	float Rect::width() const
	{
		return m_size.x;
	}

	float Rect::height() const
	{
		return m_size.y;
	}
}