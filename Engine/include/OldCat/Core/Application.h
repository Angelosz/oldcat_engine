#pragma once

#include <memory>

#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Core/GameContext.h>
#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Platform/Window.h>

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

		GameContext& context();

	private:
		std::unique_ptr<SDLContext> m_sdl;
		Window m_window;
		Renderer m_renderer;
		Input m_input;
		AssetManager m_assetManager;

		GameContext m_context;
	};
}
