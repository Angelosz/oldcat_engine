#include <OldCat/Components/ColliderComponent.h>

#include <OldCat/World/Object.h>
#include <OldCat/World/Transform.h>

namespace OldCat
{
	ColliderComponent::ColliderComponent(Object& owner, Rect rect)
		: OldCat::Component(owner), m_rect(rect) { }

	const Rect& ColliderComponent::rect() const
	{
		return m_rect;
	}

	bool ColliderComponent::contains(float x, float y) const
	{
		const Transform& transform = owner().transform();

		const float leftBorder = transform.x + m_rect.x();
		const float topBorder = transform.y + m_rect.y();

		return x >= leftBorder
			&& x <= leftBorder + m_rect.width()
			&& y >= topBorder
			&& y <= topBorder + m_rect.height();
	}
}