#include "Application.hpp"

#include <iostream>

int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch( std::exception& e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}
	catch( ... )
	{
		std::cout << "Unknown Exception." << std::endl;
		return 2;
	}
	return 0;
}