#pragma once

#include <OldCat/World/Object.h>


class Plant : public OldCat::Object
{
public:
	explicit Plant(std::string name, OldCat::GameContext& context);

	void update() override;
private:
};