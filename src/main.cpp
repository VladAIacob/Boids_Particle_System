#include <GL/glew.h>

#ifdef MACOSX
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include "Core/Engine.h"

//Creating and starting the engine.
int main(int argc, char *argv[])
{
    Engine::init(argc, argv);
    Engine::create("Boids Particle System");
    Engine::start();
    return EXIT_SUCCESS;
}