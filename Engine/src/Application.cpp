#include <OldCat/Application.h>
#include <OldCat/Detail/SDLContext.h>
#include <OldCat/Window.h>

namespace OldCat
{
	OldCat::Application::Application()
		: m_sdl(std::make_unique<SDLContext>())
		, m_window("OldCat Engine", 800, 600) {}

	OldCat::Application::~Application() = default;

	void OldCat::Application::run()
	{
		bool running = true;

		while (running)
		{
			m_input.processEvents();

			if (m_input.quitRequested())
			{
				running = false;
			}
		}
	}
}