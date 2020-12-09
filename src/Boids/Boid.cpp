#include "../include.h"
#include "Boid.h"
#include "../Core/Input.h"
#include <iostream>

bool Boid::colorChanged = false;

const GLfloat Boid::shapeBufferData[] = {
	0.1,0.1,0.1,    -0.1,0.1,0.1,    -0.1,-0.1,0.1,    0.1,-0.1,0.1,        // v0-v0.1-v2-v3
	0.1,0.1,0.1,     0.1,-0.1,0.1,    0.1,-0.1,-0.1,   0.1,0.1,-0.1,        // v0-v3-v4-v5
	0.1,0.1,0.1,     0.1,0.1,-0.1,   -0.1,0.1,-0.1,   -0.1,0.1,0.1,         // v0-v5-v6-v0.1
   -0.1,0.1,0.1,    -0.1,0.1,-0.1,   -0.1,-0.1,-0.1,  -0.1,-0.1,0.1,		// v0.1-v6-v7-v2
   -0.1,-0.1,-0.1,   0.1,-0.1,-0.1,   0.1,-0.1,0.1,   -0.1,-0.1,0.1,        // v7-v4-v3-v2
    0.1,-0.1,-0.1,  -0.1,-0.1,-0.1,  -0.1,0.1,-0.1,    0.1,0.1,-0.1			// v4-v7-v6-v5
};

Boid::Boid()
{
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		particles.push_back(new Particle());
	}

	//Shared cube shape of particles
	glGenBuffers(1, &shapeVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, shapeVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(shapeBufferData), shapeBufferData, GL_STATIC_DRAW);

}

void Boid::changeColor()
{
	if(!colorChanged && Input::isPressed(C))
	{
		for(int index = 0; index < MAX_PARTICLES; index++)
		{
			particles[index]->colour = glm::vec4((GLfloat)(rand()%255 / 255.0),
												 (GLfloat)(rand()%255 / 255.0),
												 (GLfloat)(rand()%255 / 255.0),
												 (GLfloat)1);
		}
		colorChanged = true;	
	}
	if(!Input::isPressed(C))
		colorChanged = false;
}

void Boid::update()
{
	changeColor();
	
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		particles[index]->addNeighbour(particles[index]);
		for(int neighbour = index + 1; neighbour < MAX_PARTICLES; neighbour++)
		{
			if(glm::distance(particles[index]->position, particles[neighbour]->position) <= PARTICLE_SIGHT)
			{
				particles[index]->addNeighbour(particles[neighbour]);
				particles[neighbour]->addNeighbour(particles[index]);
			}
		}
	}

	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		particles[index]->update();
	}
}

void Boid::drawBound()
{
	glLoadIdentity();
    glTranslatef(0,0,-10);
    glRotatef(Input::rotation, 0, 1, 0);
    glColor3f(0.0f, 1.0f, 1.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINES);
    
	    glVertex3i(LEFT, BOTTOM, LEFT);
	    glVertex3i(LEFT, BOTTOM, RIGHT);

	    glVertex3i(LEFT, BOTTOM, RIGHT);
	    glVertex3i(RIGHT, BOTTOM, RIGHT);

	    glVertex3i(RIGHT, BOTTOM, RIGHT);
	    glVertex3i(RIGHT, BOTTOM, LEFT);

	    glVertex3i(RIGHT, BOTTOM, LEFT);
	    glVertex3i(LEFT, BOTTOM, LEFT);


	    glVertex3i(LEFT, TOP, LEFT);
	    glVertex3i(LEFT, TOP, RIGHT);

	    glVertex3i(LEFT, TOP, RIGHT);
	    glVertex3i(RIGHT, TOP, RIGHT);

	    glVertex3i(RIGHT, TOP, RIGHT);
	    glVertex3i(RIGHT, TOP, LEFT);

	    glVertex3i(RIGHT, TOP, LEFT);
	    glVertex3i(LEFT, TOP, LEFT);



	    glVertex3i(LEFT, BOTTOM, LEFT);
	    glVertex3i(LEFT, TOP, LEFT);

	    glVertex3i(LEFT, BOTTOM, RIGHT);
	    glVertex3i(LEFT, TOP, RIGHT);

	    glVertex3i(RIGHT, BOTTOM, RIGHT);
	    glVertex3i(RIGHT, TOP, RIGHT);

	    glVertex3i(RIGHT, BOTTOM, LEFT);
	    glVertex3i(RIGHT, TOP, LEFT);

    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Boid::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, shapeVertexBuffer);
	for(int index = 0; index < MAX_PARTICLES; index++)
	{
		glLoadIdentity();
		glTranslatef(0,0,-10);
		particles[index]->draw();
	}

	drawBound();
}
