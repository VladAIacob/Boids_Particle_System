#ifndef BOID_H
#define BOID_H

#pragma once
#include <vector>
#ifndef MAX_PARTICLES
	#define MAX_PARTICLES 10
#endif
#include "Particle.h"

class Boid
{
    public:
        Boid();
        void update();
    	void draw();
    private:
    	std::vector<Particle> particles;

    	GLuint shapeVertexBuffer;
        
    	static const GLfloat shapeBufferData[];
        static const GLushort indexBufferData[];
};

#endif // BOID_H
