#pragma once

#include <memory>
#include <OldCat/Window.h>
#include <OldCat/Input.h>

namespace OldCat
{
	class SDLContext;

	class Application
	{
	public:
		Application();
		~Application();

		void run();

	private:
		std::unique_ptr<SDLContext> m_sdl;

		Window m_window;
		Input m_input;
	};
}
