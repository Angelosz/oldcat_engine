#include <OldCat/Graphics/Renderer.h>
#include <OldCat/Graphics/Texture.h>
#include <OldCat/Platform/Window.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

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

	void Renderer::drawText(const Font& font, const char* text, int x, int y)
	{
		SDL_Color color{ 255, 255, 255, 255 };

		SDL_Surface* surface = TTF_RenderText_Blended(font.m_handle, text, 0, color);

		if (surface == nullptr)
		{
			throw std::runtime_error(SDL_GetError());
		}

		SDL_Texture* texture = SDL_CreateTextureFromSurface(m_handle, surface);

		SDL_DestroySurface(surface);

		if (texture == nullptr)
		{
			throw std::runtime_error(SDL_GetError());
		}

		SDL_FRect destination{
			static_cast<float>(x),
			static_cast<float>(y),
			static_cast<float>(texture->w),
			static_cast<float>(texture->h),
		};

		SDL_RenderTexture(
			m_handle,
			texture,
			nullptr,
			&destination
		);

		SDL_DestroyTexture(texture);
	}
	void Renderer::drawTexture(const Texture& texture, int x, int y)
	{
		SDL_FRect destination{
			static_cast<float>(x),
			static_cast<float>(y),
			texture.m_width,
			texture.m_height
		};

		if (!SDL_RenderTexture(
			m_handle,
			texture.m_handle,
			nullptr,
			&destination))
		{
			throw std::runtime_error(SDL_GetError());
		}
	}
}