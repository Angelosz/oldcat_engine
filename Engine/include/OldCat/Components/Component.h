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
		const Object& owner() const;

	private:
		Object& m_owner;
	};
}