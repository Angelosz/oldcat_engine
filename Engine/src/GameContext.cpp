#include <OldCat/GameContext.h>

#include <OldCat/Renderer.h>
#include <OldCat/Input.h>
#include <OldCat/AssetManager.h>


namespace OldCat
{
	GameContext::GameContext(Renderer& renderer, Input& input, AssetManager& assetManager) 
		: m_renderer(renderer), m_input(input), m_assetManager(assetManager) { }

	Renderer& GameContext::renderer()
	{
		return m_renderer;
	}

	Input& GameContext::input()
	{
		return m_input;
	}

	AssetManager& GameContext::assetManager()
	{
		return m_assetManager;
	}
}