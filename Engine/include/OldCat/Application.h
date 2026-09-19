#pragma once

#include <memory>
#include <OldCat/Window.h>
#include <OldCat/Input.h>
#include <OldCat/Renderer.h>

namespace OldCat
{
	class Game;
	class SDLContext;

	class Application
	{
	public:
		Application();
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		void run(Game& game);

	private:
		std::unique_ptr<SDLContext> m_sdl;
		Window m_window;
		Renderer m_renderer;
		Input m_input;
	};
}
