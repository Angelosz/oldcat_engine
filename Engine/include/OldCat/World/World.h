#pragma once

#include <OldCat/World/Object.h>

#include <memory>
#include <utility>
#include <vector>

namespace OldCat
{
	class Object;
	class GameContext;

	class World
	{
		friend class Game;

	public:
		World(GameContext& gameContext);
		~World() = default;

		World(const World&) = delete;
		World& operator=(const World&) = delete;

		template<typename T, typename... Args> T& spawn(Args&&... args)
		{
			auto object = std::make_unique<T>(
				std::forward<Args>(args)...
			);

			T& objectReference = *object;

			m_objects.push_back(std::move(object));

			return objectReference;
		}

		void update(float deltaTime);
		void render();

		void destroy(Object& object);

	private:
		std::vector<std::unique_ptr<Object>> m_objects;
		GameContext& m_context;

		std::vector<Object*> m_pendingDestroy;
		void flushDestroyedObjects();
	};
}