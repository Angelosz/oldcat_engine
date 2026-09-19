#pragma once

struct TTF_Font;

namespace OldCat
{
	class Renderer;

	class Font
	{
		friend class Renderer;

	public:
		Font(const char* path, float size);
		~Font();

		Font(const Font&) = delete;
		Font& operator=(const Font&) = delete;

	private:
		TTF_Font* m_handle;
	};
}