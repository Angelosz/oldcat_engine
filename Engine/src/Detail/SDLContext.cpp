#include <OldCat/Detail/SDLContext.h>
#include <SDL3/SDL.h>
#include <stdexcept>

namespace OldCat
{
	OldCat::SDLContext::SDLContext()
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			throw std::runtime_error(SDL_GetError());
		}
	}

	OldCat::SDLContext::~SDLContext()
	{
		SDL_Quit();
	}
}

