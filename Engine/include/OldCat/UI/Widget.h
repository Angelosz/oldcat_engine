#pragma once

#include <OldCat/Math/Vector2.h>
#include <OldCat/Math/Rect.h>

namespace OldCat
{
	class AssetManager;
	class GameContext;
	class Renderer;
	class Input;

	class Widget
	{
	public:
		explicit Widget(GameContext& context, Rect bounds);
		virtual ~Widget() = default;

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;

		Vector2 position();
		const Vector2 position() const;

		Rect bounds();
		const Rect bounds() const;

	protected:
		GameContext& context();

		Input& input();
		Renderer& renderer();
		AssetManager& assetManager();

	private:
		GameContext& m_context;
		Rect m_bounds;
	};
}