#pragma once

struct SDL_Window;

namespace OldCat
{
	class Renderer;

	class Window
	{
		friend class Renderer;

	public:
		Window(const char* title, int width, int height);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		SDL_Window* m_handle;
	};
}