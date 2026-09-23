#include <OldCat/Core/Application.h>

#include <OldCat/Detail/SDLContext.h>
#include <OldCat/Core/Game.h>

namespace OldCat
{
	OldCat::Application::Application()
		: m_sdl(std::make_unique<SDLContext>())
		, m_window("OldCat Engine", 720, 1280)
		, m_renderer(m_window)
		, m_input()
		, m_assetManager(m_renderer)
		, m_context(m_renderer, m_input, m_assetManager) {}

	OldCat::Application::~Application() = default;

	void OldCat::Application::run(Game& game)
	{
		bool running = true;

		while (running)
		{
			m_input.processEvents();

			if (m_input.quitRequested())
			{
				running = false;
				continue;
			}

			game.update();

			m_renderer.clear();

			game.render();

			m_renderer.present();
		}
	}

	GameContext& Application::context()
	{
		return m_context;
	}
}