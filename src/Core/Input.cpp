#pragma once
#include <GL/glut.h>
#include "Input.h"

#ifdef MACOSX
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include <iostream>
#include "Engine.h"

bool Input::keys[NUMBER_OF_KEYS];

bool Input::isPressed(Keys key)
{
    return keys[key];
}

void Input::keyDown(unsigned char key, int x, int y)
{
    switch(tolower(key))
    {
        case 'w': keys[W] = true; break;
        case 'a': keys[A] = true; break;
        case 's': keys[S] = true; break;
        case 'd': keys[D] = true; break;
        case 27 : exit(EXIT_SUCCESS);
        case 32 : keys[SPACE] = true; break;
        default: break;
    }
}

void Input::keyUp(unsigned char key, int x, int y)
{
    switch(tolower(key))
    {
        case 'w': keys[W] = false; break;
        case 'a': keys[A] = false; break;
        case 's': keys[S] = false; break;
        case 'd': keys[D] = false; break;
        case 32 : keys[SPACE] = false; break;
        default: break;
    }
}
