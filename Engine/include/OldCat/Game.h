#pragma	once

namespace OldCat
{
	class Input;

	class Game
	{
	public:
		virtual ~Game() = default;

		virtual void update(const Input& input) = 0;
	};
}