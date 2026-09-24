#include <OldCat/Math/Rect.h>

namespace OldCat
{
	Rect::Rect(float x, float y, float width, float height)
		: m_x(x), m_y(y), m_width(width), m_height(height)
	{ }

	float Rect::x() const
	{
		return m_x;
	}

	float Rect::y() const
	{
		return m_y;
	}

	float Rect::width() const
	{
		return m_width;
	}

	float Rect::height() const
	{
		return m_height;
	}

	bool Rect::contains(float x, float y) const
	{
		return x >= m_x
			&& x <= m_x + m_width
			&& y >= m_y
			&& y <= m_y + m_height;
	}
}