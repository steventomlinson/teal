#include "OpenGLContext.h"
#include "OpenGLShader.h"
#include "OpenGLBuffer.h"
#include "OpenGLVertexArray.h"

namespace Teal
{
	std::shared_ptr<Shader> OpenGLContext::NewShader(const std::string& vstr, const std::string& fstr) 
	{
		return std::shared_ptr<OpenGLShader>(new OpenGLShader(vstr, fstr));
	}
	std::shared_ptr<Shader> OpenGLContext::NewShader(const std::string& file)
	{
		return std::shared_ptr<OpenGLShader>(nullptr);
	}


	std::shared_ptr<Buffers::Vertex> OpenGLContext::NewVertexBuffer(float* vertices, const unsigned int& size, const Buffers::Layout& layout)
	{
		return std::shared_ptr<Buffers::OpenGLVertex>(new Buffers::OpenGLVertex(vertices, size, layout));
	}
	std::shared_ptr<Buffers::Index> OpenGLContext::NewIndexBuffer(unsigned int* indices, const unsigned int& count)
	{
		return std::shared_ptr<Buffers::OpenGLIndex>(new Buffers::OpenGLIndex(indices, count));
	}
	std::shared_ptr<VertexArray> OpenGLContext::NewVertexArray(const std::vector<std::shared_ptr<Buffers::Vertex>>& vbVector, const std::shared_ptr<Buffers::Index>& ib)
	{
		return std::shared_ptr<OpenGLVertexArray>(new OpenGLVertexArray(vbVector, ib));
	}

}