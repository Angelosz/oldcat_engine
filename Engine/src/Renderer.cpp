#include <OldCat/Renderer.h>
#include <OldCat/Window.h>

#include <SDL3/SDL.h>
#include <stdexcept>

namespace OldCat
{
	Renderer::Renderer(const Window& window)
		: m_handle(nullptr)
	{
		m_handle = SDL_CreateRenderer(window.m_handle, nullptr);

		if (m_handle == nullptr)
		{
			throw std::runtime_error(SDL_GetError());
		}
	}

	Renderer::~Renderer()
	{
		if (m_handle != nullptr)
		{
			SDL_DestroyRenderer(m_handle);
		}
	}

	void Renderer::clear()
	{
		SDL_SetRenderDrawColor(m_handle, 20, 20, 20, 255); 
		SDL_RenderClear(m_handle);
	}

	void Renderer::present()
	{
		SDL_RenderPresent(m_handle);
	}
}