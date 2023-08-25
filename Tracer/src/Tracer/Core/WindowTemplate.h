#pragma once

namespace Tracer
{
	class WindowTemplate
	{
	public:
		WindowTemplate(int width = 1280, int height = 720, const char* title = "Tracer") :
			m_Data({ width, height, title })
		{}
		virtual ~WindowTemplate() {};
		virtual void OnUpdate() = 0;

	protected:
		virtual void Init() = 0;

		struct WindowData
		{
			int width;
			int height;
			const char* title;
		};

		WindowData m_Data;
	};
}