#pragma once
#include <string>

namespace OldCat
{
	class Font;

	struct Text
	{
		Font& font;
		std::string content;
	};
}