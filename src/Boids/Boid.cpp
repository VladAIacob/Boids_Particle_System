#include "../include.h"
#include "Boid.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

const GLfloat Boid::shapeBufferData[] = {
	1,1,1,    -1,1,1,    -1,-1,1,    1,-1,1,        // v0-v1-v2-v3
	1,1,1,     1,-1,1,    1,-1,-1,   1,1,-1,        // v0-v3-v4-v5
	1,1,1,     1,1,-1,   -1,1,-1,   -1,1,1,         // v0-v5-v6-v1
   -1,1,1,    -1,1,-1,   -1,-1,-1,  -1,-1,1,		// v1-v6-v7-v2
   -1,-1,-1,   1,-1,-1,   1,-1,1,   -1,-1,1,        // v7-v4-v3-v2
    1,-1,-1,  -1,-1,-1,  -1,1,-1,    1,1,-1			// v4-v7-v6-v5
};

Boid::Boid()
{
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		particles.push_back(Particle());
	}

	//Shared cube shape of particles
	glGenBuffers(1, &shapeVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, shapeVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(shapeBufferData), shapeBufferData, GL_STATIC_DRAW);

}

void Boid::update()
{
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		particles[index].update();
	}
}

void Boid::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, shapeVertexBuffer);
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		glLoadIdentity();
		glTranslatef(0,0,-10);
		particles[index].draw();
	}
}
