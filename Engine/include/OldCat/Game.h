#pragma	once

namespace OldCat
{
	class Input;
	class Renderer;

	class Game
	{
	public:
		virtual ~Game() = default;

		virtual void update(const Input& input) = 0;
		virtual void render(Renderer& renderer) = 0;
	};
}