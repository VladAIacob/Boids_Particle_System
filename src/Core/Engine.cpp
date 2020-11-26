#pragma once
#include <GL/glew.h>

#ifdef MACOSX
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include "Engine.h"
#include <iostream>

Engine *Engine::engine = NULL;

int Engine::getWidth()
{
    return width;
}

int Engine::getHeight()
{
    return height;
}

Engine::Engine()
: width(WIDTH), height(HEIGHT), frameCount(0)
{
    currentTime = timeSinceLastFPScheck = glutGet(GLUT_ELAPSED_TIME);
}

Engine* Engine::getInstance()
{
    return engine;
}

void Engine::idle()
{
    glutPostRedisplay();
}

void Engine::stop()
{

}

void Engine::start()
{
    glutMainLoop();
}

void Engine::create(const char *name)
{
    glutCreateWindow(name);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glutReshapeFunc(Engine::resize);
    glutDisplayFunc(Engine::mainLoop);
    glutIdleFunc(Engine::idle);
}

void Engine::update()
{ 
}

void Engine::display()
{
}

void Engine::mainLoop()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity();

    update();
    display();

    engine->frameCount++;
    engine->currentTime = glutGet(GLUT_ELAPSED_TIME);
    if(engine->currentTime - engine->timeSinceLastFPScheck > 1000)
    {
        std::cout << "[DEBUG] FPS: " << engine->frameCount << std::endl;
        engine->frameCount = 0;
        engine->timeSinceLastFPScheck = glutGet(GLUT_ELAPSED_TIME);
    }

    glutSwapBuffers();
}

void Engine::init(int argc, char *argv[])
{
    glewInit();
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    if(!engine)
        engine = new Engine();
}

void Engine::resize(int width, int height)
{
    const float aspect = (float) width / (float) height;
    engine->width = width;
    engine->height = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}