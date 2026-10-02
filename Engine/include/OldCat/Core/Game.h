#pragma	once

#include <OldCat/World/World.h>
#include <OldCat/UI/UI.h>

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

		void updateGame(float deltaTime);
		void renderGame();

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;

		void updateUI(float deltaTime);
		void renderUI();

		void endOfFrame();

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

		template<typename T, typename... Args>
		T& addWidget(Args&&... args)
		{
			return m_ui.addWidget<T>(
				std::forward<Args>(args)...
			);
		}

		void destroy(Object& object);

	private:
		GameContext& m_context;
		World m_world;
		UI m_ui;
	};
}