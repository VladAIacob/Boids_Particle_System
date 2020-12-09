#ifndef BOID_H
#define BOID_H

#pragma once
#include <vector>
#include "Particle.h"

#ifndef BOID_LOGIC
    #define BOID_LOGIC
    #define MAX_PARTICLES 1000
#endif

class Boid
{
    public:
        //Boid constructor
        Boid();
        //A method to update each particle in the flock
        void update();
        //A method to draw each particle in the flock
    	void draw();
        //A method to draw the enclosure
        void drawBound();
    private:
        //A vector containing pointers to all the particles
    	std::vector<Particle *> particles;

        //A shared shape buffer representing a cube
    	GLuint shapeVertexBuffer;
        
    	static const GLfloat shapeBufferData[];

        //A method to change all particles colour
        static bool colorChanged;
        void changeColor();
};

#endif // BOID_H
