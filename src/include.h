#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#ifdef MACOSX
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif
#include <glm/glm.hpp>
