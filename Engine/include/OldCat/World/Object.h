#pragma once

#include <OldCat/Components/Component.h>

#include <memory>
#include <utility>
#include <vector>
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

		template<typename T, typename... Args>
		T& addComponent(Args&&... args)
		{
			auto component = std::make_unique<T>(
				*this,
				std::forward<Args>(args)...
			);

			T& reference = *component;

			m_components.push_back(std::move(component));

			return reference;
		}

		template<typename T>
		T* getComponent()
		{
			for (const auto& component : m_components)
			{
				if (T* result = dynamic_cast<T*>(component.get()))
				{
					return *result;
				}
			}
			
			return nullptr;
		}

		const std::vector<std::unique_ptr<Component>>& getComponents() const;
		const std::string& name() const;

	protected:
		GameContext& context();

	private:
		std::string m_name;
		GameContext& m_context;

		std::vector<std::unique_ptr<Component>> m_components;
	};
}