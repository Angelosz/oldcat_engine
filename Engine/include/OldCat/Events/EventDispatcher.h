#pragma once

#include <functional>
#include <vector>

namespace OldCat
{
	class EventDispatcher
	{
	public:
		void onClicked(std::function<void()> callback);
		void clicked();

	private:
		std::vector<std::function<void()>> m_clickedCallbacks;
	};
}