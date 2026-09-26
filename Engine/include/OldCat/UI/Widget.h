#pragma once

#include <OldCat/Math/Vector2.h>

namespace OldCat
{
	class AssetManager;
	class GameContext;
	class Renderer;
	class Input;

	class Widget
	{
	public:
		explicit Widget(GameContext& context, Vector2 position);
		virtual ~Widget() = default;

		virtual void update() = 0;
		virtual void render() = 0;

		Vector2 position();
		const Vector2 position() const;

	protected:
		GameContext& context();

		Input& input();
		Renderer& renderer();
		AssetManager& assetManager();

	private:
		GameContext& m_context;
		Vector2 m_position;
	};
}