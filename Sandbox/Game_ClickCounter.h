#pragma once

#include <OldCat/Game.h>

namespace OldCat
{
	class Input;
}

class Game_ClickCounter : public OldCat::Game
{
public:
	void update(const OldCat::Input& input) override;

private:
	int m_counter = 0;
};