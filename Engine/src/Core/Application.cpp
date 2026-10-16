#include <OldCat/Core/Application.h>

#include <OldCat/Detail/SDLContext.h>
#include <OldCat/Core/Scene.h>

namespace OldCat
{
	OldCat::Application::Application(const char* appName, OldCat::Vector2 windowSize)
		: m_sdl(std::make_unique<SDLContext>())
		, m_window(
			appName,
			static_cast<int>(windowSize.x),
			static_cast<int>(windowSize.y)
		)
		, m_renderer(m_window)
		, m_input()
		, m_assetManager(m_renderer)
		, m_context(m_renderer, m_input, m_assetManager) {}

	OldCat::Application::~Application() = default;

	void OldCat::Application::run(Scene& game)
	{
		bool running = true;

		while (running)
		{
			m_time.update();

			m_input.processEvents();
			if (m_input.quitRequested())
			{
				running = false;
				continue;
			}

			game.updateGame(m_time.deltaTime());

			game.endOfFrame();

			m_renderer.clear();
			game.renderGame();
			m_renderer.present();

		}
	}

	GameContext& Application::context()
	{
		return m_context;
	}
}