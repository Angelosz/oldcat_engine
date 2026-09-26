#include <OldCat/Core/Game.h>
#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Game::Game(GameContext& gameContext)
		: m_context(gameContext), m_world(gameContext), m_ui(gameContext) { }

	void Game::updateGame()
	{
		m_world.update();
		update();
		updateUI();
	}

	void Game::renderGame()
	{
		m_world.render();
		render();
		renderUI();
	}

	void Game::updateUI()
	{
		m_ui.update();
	}

	void Game::renderUI()
	{
		m_ui.render();
	}

	GameContext& Game::context()
	{
		return m_context;
	}

	Renderer& Game::renderer()
	{
		return m_context.renderer();
	}

	Input& Game::input()
	{
		return m_context.input();
	}


	AssetManager& Game::assetManager()
	{
		return m_context.assetManager();
	}
}