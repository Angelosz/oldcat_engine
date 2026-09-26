#include <OldCat/Core/Time.h>

namespace OldCat
{
	Time::Time()
		: m_lastTime(Clock::now()) { }

	void Time::update()
	{
		const Clock::time_point currentTime = Clock::now();
		const std::chrono::duration<float> elapsed = currentTime - m_lastTime;

		m_deltaTime = elapsed.count();
		m_lastTime = currentTime;
	}

	float Time::deltaTime() const
	{
		return m_deltaTime;
	}
}