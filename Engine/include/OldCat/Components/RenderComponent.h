#pragma once

#include <OldCat/Components/Component.h>

namespace OldCat
{
	class Object;
	class Renderer;

	class RenderComponent : public OldCat::Component
	{
	public:
		explicit RenderComponent(OldCat::Object& object);

		virtual void render(OldCat::Renderer& renderer) = 0;
	};
}