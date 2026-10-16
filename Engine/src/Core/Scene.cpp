#include <OldCat/Core/Scene.h>
#include <OldCat/Core/GameContext.h>

namespace OldCat
{
	Scene::Scene(GameContext& gameContext)
		: m_context(gameContext), m_world(gameContext), m_ui(gameContext) { }

	void Scene::updateGame(float deltaTime)
	{
		m_world.update(deltaTime);
		update(deltaTime);
		updateUI(deltaTime);
	}

	void Scene::renderGame()
	{
		m_world.render();
		render();
		renderUI();
	}

	void Scene::updateUI(float deltaTime)
	{
		m_ui.update(deltaTime);
	}

	void Scene::endOfFrame()
	{
		m_world.flushDestroyedObjects();
	}

	void Scene::destroy(Object& object)
	{
		m_world.destroy(object);
	}

	void Scene::renderUI()
	{
		m_ui.render();
	}

	GameContext& Scene::context()
	{
		return m_context;
	}

	Renderer& Scene::renderer()
	{
		return m_context.renderer();
	}

	Input& Scene::input()
	{
		return m_context.input();
	}


	AssetManager& Scene::assetManager()
	{
		return m_context.assetManager();
	}
}