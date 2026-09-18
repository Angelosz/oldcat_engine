#pragma once

#include <array>

namespace OldCat
{
	enum class MouseButton
	{
		Left = 0,
		Middle,
		Right
	};

	class Input
	{
	public:
		void processEvents();

		bool quitRequested() const;
		bool wasMouseButtonPressed(MouseButton button) const;

	private:
		bool m_quitRequested = false;
		std::array<bool, 3> m_mouseButtonPressed{};
	};
}