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

	class Scene
	{
	public:
		explicit Scene(GameContext& gameContext);
		virtual ~Scene() = default;

		void updateScene(float deltaTime);
		void renderScene();

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;

		void updateUI(float deltaTime);
		void renderUI();

		void endOfFrame();

		virtual void onCreated() = 0;

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