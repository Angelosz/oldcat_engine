#include <OldCat/Core/GameContext.h>

#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Input/Input.h>
#include <OldCat/Assets/AssetManager.h>


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