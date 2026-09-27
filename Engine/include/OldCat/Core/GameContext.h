#pragma once

namespace OldCat
{
	class Renderer;
	class Input;
	class AssetManager;

	class GameContext
	{
	public:
		GameContext(
			Renderer& renderer,
			Input& input,
			AssetManager& assetManager
		);

		Renderer& renderer();
		Input& input();
		AssetManager& assetManager();

	private:
		Renderer& m_renderer;
		Input& m_input;
		AssetManager& m_assetManager;
	};
}