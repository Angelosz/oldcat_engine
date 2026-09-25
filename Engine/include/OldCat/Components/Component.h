#pragma once

namespace OldCat
{
	class Object;

	class Component
	{
	public:
		explicit Component(Object& owner);
		virtual ~Component() = default;

		Component(const Component&) = delete;
		Component& operator=(const Component&) = delete;

		Object& owner();

	private:
		Object& m_owner;
	};
}