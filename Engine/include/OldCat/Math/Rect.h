#pragma once

namespace OldCat
{
	class Rect
	{
	public:
		Rect(float x, float y, float width, float height);

		float x() const;
		float y() const;
		float width() const;
		float height() const;

		bool contains(float x, float y) const;

	private:
		float m_x;
		float m_y;
		float m_width;
		float m_height;
	};
}