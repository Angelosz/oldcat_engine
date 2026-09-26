#include <OldCat/Components/ColliderComponent.h>

#include <OldCat/Input/Input.h>
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

	bool ColliderComponent::contains(Vector2 point) const
	{
		const Transform& transform = owner().transform();

		const float leftBorder = transform.x() + m_rect.x();
		const float topBorder = transform.y() + m_rect.y();

		return point.x >= leftBorder
			&& point.x <= leftBorder + m_rect.width()
			&& point.y >= topBorder
			&& point.y <= topBorder + m_rect.height();
	}

	bool ColliderComponent::wasClicked(const Input& input) const
	{
		return input.wasMouseButtonPressed(MouseButton::Left)
			&& contains(input.mousePosition());
	}
}