#include <OldCat/Game.h>
#include <OldCat/GameContext.h>

namespace OldCat
{
	Game::Game(GameContext& gameContext)
		: m_context(gameContext){ }

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