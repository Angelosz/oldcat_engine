#pragma once

#include <OldCat/Math/Vector2.h>

namespace OldCat
{
	struct Transform
	{
		Vector2 position = Vector2(0.0f, 0.0f);

		const float x() const
		{
			return position.x;
		}

		const float y() const
		{
			return position.y;
		}
	};
}