#pragma once

struct SDL_Window;

namespace OldCat
{
	class Window
	{
	public:
		Window(const char* title, int width, int height);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		SDL_Window* getHandle() const;

	private:
		SDL_Window* m_handle;
	};
}