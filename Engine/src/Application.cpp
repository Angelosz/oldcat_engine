#include <OldCat/Application.h>
#include <OldCat/Window.h>
#include <SDL3/SDL.h>
#include <stdexcept>

namespace OldCat
{
	OldCat::Application::Application()
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			throw std::runtime_error(SDL_GetError());
		}

		m_window = std::make_unique<Window>(
			"OldCat Engine",
			800,
			600
		);
	}

	OldCat::Application::~Application()
	{
		m_window.reset();

		SDL_Quit();
	}

	void OldCat::Application::run()
	{
		bool running = true;

		while (running)
		{
			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_EVENT_QUIT)
				{
					running = false;
				}
			}
		}
	}
}
