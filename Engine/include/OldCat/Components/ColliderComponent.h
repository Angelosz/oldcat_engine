#pragma once

#include <OldCat/Components/Component.h>
#include <OldCat/Math/Rect.h>

namespace OldCat
{
	class ColliderComponent : public OldCat::Component
	{
	public:
		explicit ColliderComponent(Object& owner, Rect rect);

		const Rect& rect() const;

		bool contains(Vector2 point) const;

	private:
		Rect  m_rect;
	};
}