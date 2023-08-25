#include "tcpch.h"
#include "Application.h"
#include "Core/Window.h"

namespace Tracer
{
	Application::Application() :
		m_Window(std::unique_ptr<WindowTemplate>(new Window()))
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
		}
	}
}