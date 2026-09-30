#pragma once

#include <OldCat/Input/Key.h>
#include <OldCat/Input/MouseButton.h>
#include <OldCat/Math/Vector2.h>

#include <array>

namespace OldCat
{

	class Input
	{
	public:
		void processEvents();

		bool quitRequested() const;

		bool wasMouseButtonPressed(MouseButton button) const;
		bool wasKeyPressed(Key key) const;

		Vector2 mousePosition() const;

	private:
		bool m_quitRequested = false;

		std::array<bool, 3> m_mouseButtonPressed{};
		std::array<bool, 4> m_keyPressed{};

		Vector2 m_mousePosition;
	};
}