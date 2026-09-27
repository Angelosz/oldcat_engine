#pragma once

#include <OldCat/Math/Vector2.h>

#include <array>

namespace OldCat
{
	enum class MouseButton
	{
		Left,
		Middle,
		Right
	};

	class Input
	{
	public:
		void processEvents();

		bool quitRequested() const;
		bool wasMouseButtonPressed(MouseButton button) const;

		Vector2 mousePosition() const;

	private:
		bool m_quitRequested = false;
		Vector2 m_mousePosition;
		std::array<bool, 3> m_mouseButtonPressed{};
	};
}