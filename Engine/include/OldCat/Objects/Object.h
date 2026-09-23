#pragma once

#include <string>

namespace OldCat
{
	class Renderer;
	class Input;
	class AssetManager;
	class GameContext;

	class Object
	{
	public:
		explicit Object(std::string name, GameContext& context);
		virtual ~Object() = default;

		virtual void update() = 0;
		virtual void render() = 0;

	protected:
		GameContext& context();

		Renderer& renderer();
		Input& input();
		AssetManager& assetManager();

	private:
		std::string m_name;
		GameContext& m_context;
	};
}