#pragma once

#include "WindowTemplate.h"
#include "GLFW/glfw3.h"

namespace Tracer
{
	class Window : public WindowTemplate
	{
	public:
		Window();
		Window(int width, int height, const char* title);
		~Window() override;

		void OnUpdate() override;

	private:
		void Init() override;
		GLFWwindow* m_Window = nullptr;
	};
}
