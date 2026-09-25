#pragma once

#include <OldCat/World/Object.h>
#include <OldCat/Math/Rect.h>

namespace OldCat
{
	class SpriteComponent;

	class SpriteObject : public OldCat::Object
	{
	public:
		explicit SpriteObject(std::string name, OldCat::GameContext& context, const char* path, OldCat::Rect rect);

		void update() override;

	private:
		SpriteComponent* m_spriteComponent;
	};
}