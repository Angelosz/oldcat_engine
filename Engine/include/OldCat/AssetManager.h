#pragma once

#include <OldCat/Texture.h>

namespace OldCat
{
	class Renderer;

	class AssetManager
	{
	public:
		explicit AssetManager(Renderer& renderer);

		Texture loadTexture(const char* path);

	private:
		Renderer& m_renderer;
	};
}