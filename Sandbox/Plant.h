#pragma once

#include <OldCat/World/Object.h>
#include <OldCat/Graphics/Sprite.h>


class Plant : public OldCat::Object
{
public:
	Plant(std::string name, OldCat::GameContext& context, OldCat::Sprite sprite);

	void update() override;

private:
	OldCat::Sprite m_sprite;
};
