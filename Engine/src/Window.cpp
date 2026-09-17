#include <OldCat/Window.h>
#include <SDL3/SDL.h>
#include <stdexcept>

OldCat::Window::Window(const char* title, int width, int height)
	: m_handle(nullptr)
{
	m_handle = SDL_CreateWindow(title, width, height, 0);

	if (m_handle == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

OldCat::Window::~Window()
{
	if (m_handle != nullptr)
	{
		SDL_DestroyWindow(m_handle);
	}
}

SDL_Window* OldCat::Window::getHandle() const
{
	return m_handle;
}
