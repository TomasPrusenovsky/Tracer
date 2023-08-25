#pragma once
#include "Core/WindowTemplate.h"
#include "tcpch.h"

namespace Tracer
{
	class TRACER_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		std::unique_ptr<WindowTemplate> m_Window;
	};
}


