#include "tcpch.h"
#include "Window.h"

namespace Tracer
{
	static bool s_GLFWInitialized = false;

	Window::Window()
	{
		Init();
	}

	Window::Window(int width, int height, const char* title) :
		WindowTemplate(width, height, title)
	{
		Init();
	}

	Window::~Window()
	{

	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::Init()
	{
		if (!s_GLFWInitialized)
		{
			int succes = glfwInit();
			TC_CORE_ASSERT(succes, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title, NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
	}
}
