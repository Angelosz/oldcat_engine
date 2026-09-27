#pragma once

#include <OldCat/UI/Widget.h>

#include <vector>
#include <utility>
#include <memory>

namespace OldCat
{
	class GameContext;

	class UI
	{
	public:
		explicit UI(GameContext& gameContext);

		UI(const UI&) = delete;
		UI& operator=(const UI&) = delete;

		template<typename T, typename... Args>
		T& addWidget(Args&&... args)
		{
			auto widget = std::make_unique<T>(
				m_context,
				std::forward<Args>(args)...
			);

			T& reference = *widget;

			m_widgets.push_back(std::move(widget));

			return reference;
		}

		void update(float deltaTime);
		void render();

	private:
		GameContext& m_context;
		std::vector<std::unique_ptr<Widget>> m_widgets;
	};
}