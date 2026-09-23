#pragma once
#include <OldCat/Graphics/Font.h>

struct SDL_Renderer;

namespace OldCat
{
	class Window;
	class Texture;

	class Renderer
	{
		friend class Texture;

	public:
		explicit Renderer(const Window& window);
		~Renderer();

		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;

		void clear();
		void present();

		void drawText(const Font& font, const char* text, int x, int y);
		void drawTexture(const Texture& texture, int x, int y);

	private:
		SDL_Renderer* m_handle;
	};
}