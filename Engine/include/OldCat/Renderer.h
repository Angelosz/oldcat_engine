#pragma once

struct SDL_Renderer;

namespace OldCat
{
	class Window;

	class Renderer
	{
	public:
		explicit Renderer(const Window& window);
		~Renderer();

		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;

		void clear();
		void present();

	private:
		SDL_Renderer* m_handle;
	};
}