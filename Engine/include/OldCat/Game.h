#pragma	once

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

		virtual void update() = 0;
		virtual void render() = 0;

	protected:
		GameContext& context();

		Renderer& renderer();
		Input& input();
		AssetManager& assetManager();

	private:
		GameContext& m_context;
	};
}