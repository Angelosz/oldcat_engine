#include <OldCat/Texture.h>
#include <OldCat/Renderer.h>

#include <SDL3/SDL.h>

#include <stdexcept>
#include <utility>

namespace OldCat
{
	Texture::Texture(Renderer& renderer, const char* path)
		: m_handle(nullptr)
		, m_width(0)
		, m_height(0)
	{
		SDL_Surface* surface = SDL_LoadPNG(path);

		if (surface == nullptr)
		{
			throw std::runtime_error(SDL_GetError());
		}

		m_handle = SDL_CreateTextureFromSurface(
			renderer.m_handle,
			surface
		);

		SDL_DestroySurface(surface);

		if (m_handle == nullptr)
		{
			throw std::runtime_error(SDL_GetError());
		}

		if (!SDL_GetTextureSize(
			m_handle,
			&m_width,
			&m_height))
		{
			SDL_DestroyTexture(m_handle);
			m_handle = nullptr;

			throw std::runtime_error(SDL_GetError());
		}
	}

	Texture::~Texture()
	{
		if (m_handle != nullptr)
		{
			SDL_DestroyTexture(m_handle);
		}
	}

	Texture::Texture(Texture&& other) noexcept
		: m_handle(other.m_handle)
		, m_width(other.m_width)
		, m_height(other.m_height)
	{
		other.m_handle = nullptr;
		other.m_width = 0;
		other.m_height = 0;
	}

	Texture& Texture::operator=(Texture&& other) noexcept
	{
		if (this != &other)
		{
			if (m_handle != nullptr)
			{
				SDL_DestroyTexture(m_handle);
			}

			m_handle = other.m_handle;
			m_width = other.m_width;
			m_height = other.m_height;

			other.m_handle = nullptr;
			other.m_width = 0;
			other.m_height = 0;
		}

		return *this;
	}
}