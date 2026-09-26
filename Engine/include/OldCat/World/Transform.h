#pragma once

#include <OldCat/Math/Vector2.h>

namespace OldCat
{
	struct Transform
	{
		Vector2 position;

		float x() const
		{
			return position.x;
		}

		float y() const
		{
			return position.y;
		}
	};
}