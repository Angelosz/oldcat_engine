#pragma	once

#include <OldCat/World/World.h>

#include <utility>

namespace OldCat
{
	class Renderer;
	class Input;
	class AssetManager;
	class GameContext;

	class Game
	{
	public:
		explicit Game(GameContext& gameContext);
		virtual ~Game() = default;

		void updateGame();

		virtual void update() = 0;
		virtual void render() = 0;

	protected:
		GameContext& context();

		Renderer& renderer();
		Input& input();
		AssetManager& assetManager();

		template<typename T, typename... Args> T& spawn(Args&&... args)
		{
			return m_world.spawn<T>(
				std::forward<Args>(args)...
			);
		}

	private:
		GameContext& m_context;
		World m_world;
	};
}