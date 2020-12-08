#include <stdlib.h>     
#include <time.h>
#include <iostream>  
#include <exception>

#include "include.h"
#include "Core/Engine.h"     

//Creating and starting the engine.
int main(int argc, char *argv[])
{
	srand (time(NULL));
	try
	{
    	Engine::init(argc, argv);
    	Engine::create("Boids Particle System");
    	std::cout << "[DEBUG] Starting the particle system!" << std::endl;
    	Engine::start();
    }
    catch(std::exception& e)
    {
    	std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}