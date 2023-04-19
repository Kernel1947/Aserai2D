#pragma once

#include "AseraiEngine/Renderer/VertexBuffer.h"
#include "AseraiEngine/Renderer/IndexBuffer.h"

#include <memory>
#include <vector>

namespace Aserai
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vb);
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ib);

		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const;
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const;

	private:
		uint32_t m_ArrayID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}
