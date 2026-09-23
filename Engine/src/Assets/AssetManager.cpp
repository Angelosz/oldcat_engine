#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Renderer.h>

namespace OldCat
{
	AssetManager::AssetManager(Renderer& renderer)
		: m_renderer(renderer) { }

	Texture AssetManager::loadTexture(const char* path)
	{
		return Texture(m_renderer, path);
	}

	Texture AssetManager::loadTexture(const std::string& path)
	{
		return Texture(m_renderer, path.c_str());
	}
}