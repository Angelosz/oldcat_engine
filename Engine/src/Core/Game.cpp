#include <OldCat/Core/Game.h>
#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Game::Game(GameContext& gameContext)
		: m_context(gameContext){ }

	void Game::updateWorld()
	{
		m_world.update();
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