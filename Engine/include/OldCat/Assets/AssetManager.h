#pragma once

#include <OldCat/Graphics/Texture.h>

#include <string>

namespace OldCat
{
	class Renderer;

	class AssetManager
	{
	public:
		explicit AssetManager(Renderer& renderer);

		Texture loadTexture(const char* path);
		Texture loadTexture(const std::string& path);

	private:
		Renderer& m_renderer;
	};
}