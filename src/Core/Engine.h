#ifndef ENGINE_H
#define ENGINE_H

#define WIDTH 640
#define HEIGHT 480

#pragma once

class Engine
{
    public:

        int getWidth();
        int getHeight();

        static Engine* getInstance();
        //The idle callback function
        static void idle();
        //Used to stop the Engine
        static void stop();
        //Used to start the Engine, the Engine must first be initializedd and created.
        static void start();
        //Used to create the Engine and the window
        static void create(const char *name);
        //Used to update the Engine
        static void update();
        //Used to display the scene to the screen
        static void display();
        //The display callback function here referenced as the mainLoop
        static void mainLoop();
        //Used to initialize the Engine and glut
        static void init(int argc, char *argv[]);
        //The resize callback function
        static void resize(int width, int height);

    private:
        //The dimensions of the Engine window
        int width, height;
        int frameCount;
        unsigned long long timeSinceLastFPScheck, currentTime;
        //The Engine instance
        static Engine *engine;
        //There can only be one Engine instance, thus the constructor is private
        Engine();
};

#endif // ENGINE_H
