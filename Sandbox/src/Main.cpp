#include "Tracer.h"
#include "iostream"

class Sandbox : public Tracer::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

int main(int argc, char** argv)
{
	auto app = new Sandbox();
	app->Run();
	delete app;
}