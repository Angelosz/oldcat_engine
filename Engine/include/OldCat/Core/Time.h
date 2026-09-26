#pragma once

#include <chrono>

namespace OldCat
{
	class Time
	{
	public:
		Time();

		void update();

		float deltaTime() const;

	private:
		using Clock = std::chrono::steady_clock;

		Clock::time_point m_lastTime;
		float m_deltaTime = 0.0f;
	};
}