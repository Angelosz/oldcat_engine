#pragma once

struct SDL_Texture;

namespace OldCat
{
	class Renderer;

	class Texture
	{
		friend class Renderer;

	public:
		Texture(Renderer& renderer, const char* path);
		~Texture();

		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;

		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

	private:
		SDL_Texture* m_handle;
		float m_width;
		float m_height;
	};
}