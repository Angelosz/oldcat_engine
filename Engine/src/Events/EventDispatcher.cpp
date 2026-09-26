#include <OldCat/Events/EventDispatcher.h>

#include <utility>

void OldCat::EventDispatcher::onClicked(std::function<void()> callback)
{
	m_clickedCallbacks.push_back(std::move(callback));
}

void OldCat::EventDispatcher::clicked()
{
	for (auto& callback : m_clickedCallbacks)
	{
		callback();
	}
}
