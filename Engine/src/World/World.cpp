#include <OldCat/World/World.h>

#include <utility>

namespace OldCat
{
	void World::update()
	{
		for (auto& object : m_objects)
		{
			object->update();
		}
	}
}