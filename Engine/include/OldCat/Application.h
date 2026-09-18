#pragma once

#include <memory>
#include <OldCat/Window.h>
#include <OldCat/Input.h>
#include <OldCat/Game.h>

namespace OldCat
{
	class SDLContext;

	class Application
	{
	public:
		Application(Game& game);
		~Application();

		void run();

	private:
		Game& m_game;

		std::unique_ptr<SDLContext> m_sdl;
		Window m_window;
		Input m_input;
	};
}
