#include <OldCat/Graphics/Font.h>

#include <SDL3_ttf/SDL_ttf.h>

#include <stdexcept>
#include <string>

namespace OldCat
{
	Font::Font(const char* path, float size)
		: m_handle(nullptr)
	{

		m_handle = TTF_OpenFont(path, size);

		if (m_handle == nullptr)
		{
			throw std::runtime_error(
				std::string("Failed to load font: ") +
				path +
				"\nSDL error: " +
				SDL_GetError()
			);
		}
	}

	Font::~Font()
	{
		if (m_handle != nullptr)
		{
			TTF_CloseFont(m_handle);
		}
	}
}