#include <OldCat/Assets/AssetManager.h>
#include <OldCat/Graphics/Renderer.h>

namespace OldCat
{
	AssetManager::AssetManager(Renderer& renderer)
		: m_renderer(renderer) { }

	Texture& AssetManager::loadTexture(const char* path)
	{
		return loadTexture(std::string(path));
	}

	Texture& AssetManager::loadTexture(const std::string& path)
	{
		std::unordered_map<std::string, std::unique_ptr<Texture>>::iterator
			it = m_textures.find(path);

		if (it != m_textures.end())
		{
			return *it->second;
		}

		std::unique_ptr<Texture> texture = std::make_unique<Texture>(m_renderer, path.c_str());

		Texture& textureReference = *texture;
		
		m_textures.emplace(path, std::move(texture));

		return textureReference;
	}
}