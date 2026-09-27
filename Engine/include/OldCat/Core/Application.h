#pragma once

#include <memory>

#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Platform/Window.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Math/Vector2.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Core/Time.h>


namespace OldCat
{
	class Game;
	class SDLContext;

	class Application
	{
	public:
		Application(const char* appName, OldCat::Vector2 windowSize);
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		void run(Game& game);

		GameContext& context();

	private:
		std::unique_ptr<SDLContext> m_sdl;
		Window m_window;
		Renderer m_renderer;
		Input m_input;
		AssetManager m_assetManager;

		GameContext m_context;
		Time m_time;
	};
}
