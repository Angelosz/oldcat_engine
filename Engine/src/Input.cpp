#include <OldCat/Input.h>
#include <SDL3/SDL.h>

namespace OldCat
{
	void Input::processEvents()
	{
		m_quitRequested = false;
		m_mouseButtonPressed.fill(false);

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_QUIT:
				m_quitRequested = true;
				break;

			case SDL_EVENT_MOUSE_BUTTON_DOWN:
			{

				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					m_mouseButtonPressed[static_cast<std::size_t>(MouseButton::Left)] = true;
					break;

				case SDL_BUTTON_MIDDLE:
					m_mouseButtonPressed[static_cast<std::size_t>(MouseButton::Middle)] = true;
					break;

				case SDL_BUTTON_RIGHT:
					m_mouseButtonPressed[static_cast<std::size_t>(MouseButton::Right)] = true;
					break;
				}
				break;
			}}
		}
	}

	bool Input::quitRequested() const
	{
		return m_quitRequested;
	}

	bool Input::wasMouseButtonPressed(MouseButton button) const
	{
		return m_mouseButtonPressed[static_cast<std::size_t>(button)];
	}


}