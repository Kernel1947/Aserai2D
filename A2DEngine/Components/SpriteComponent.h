#pragma once

#include "A2DEngine/Asset/AssetManager.h"
#include "A2DEngine/Asset/TextureAsset.h"

#include <glm/glm.hpp>
#include <memory>
#include <array>

namespace Aserai2D
{
	struct SpriteComponent
	{
		glm::vec4 Color;
		uint32_t Width;
		uint32_t Height;
		uint32_t ZIndex;
		AssetID Texture;
		std::array<glm::vec2, 4> TextureUV;
		bool Fixed;

		SpriteComponent(const glm::vec4& color = glm::vec4({ 1.0f, 1.0f, 1.0f, 1.0f }), uint32_t width = 1, uint32_t height = 1, uint32_t zIndex = 0, bool fixed = false)
			: Color(color), Width(width), Height(height), ZIndex(zIndex), Fixed(fixed), Texture(0), TextureUV({ glm::vec2{ 0.0f, 0.0f }, glm::vec2{ 1.0f, 0.0f }, glm::vec2{ 1.0f, 1.0f }, glm::vec2{ 0.0f, 1.0f } })
		{
		}

		SpriteComponent(AssetID texture, uint32_t width = 1, uint32_t height = 1, uint32_t zIndex = 0, const std::array<glm::vec2, 4> textureUV = { glm::vec2{ 0.0f, 0.0f }, glm::vec2{ 1.0f, 0.0f }, glm::vec2{ 1.0f, 1.0f }, glm::vec2{ 0.0f, 1.0f } }, bool fixed = false)
			: Color({ 1.0f, 1.0f, 1.0f, 1.0f }), Width(width), Height(height), ZIndex(zIndex), Fixed(fixed), Texture(texture), TextureUV(textureUV)
		{
		}
	};
}
