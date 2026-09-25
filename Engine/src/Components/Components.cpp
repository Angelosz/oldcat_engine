#include <OldCat/Components/Component.h>

namespace OldCat
{
	Component::Component(Object& owner)
		: m_owner(owner) { }

	Object& Component::owner()
	{
		return m_owner;
	}
}