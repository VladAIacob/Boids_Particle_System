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
        Boid();
        void update();
    	void draw();
        void drawBound();
    private:
    	std::vector<Particle *> particles;

    	GLuint shapeVertexBuffer;
        
    	static const GLfloat shapeBufferData[];
        static const GLushort indexBufferData[];
};

#endif // BOID_H
