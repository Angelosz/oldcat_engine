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

	protected:
		GameContext& context();

	private:
		std::string m_name;
		GameContext& m_context;
	};
}