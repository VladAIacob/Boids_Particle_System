#include <stdlib.h>     
#include <time.h>
#include <iostream>  
#include <exception>

#include "include.h"
#include "Core/Engine.h"     

//Creating and starting the engine.
int main(int argc, char *argv[])
{
	//Initialize random
	srand (time(NULL));
	//Try to initialize the engine and create a window 
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