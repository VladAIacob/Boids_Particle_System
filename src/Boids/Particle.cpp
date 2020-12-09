#pragma once
#include <stdlib.h>
#include "Particle.h"
#include "../Core/Input.h"

Particle::Particle()
:position((GLfloat)(rand() % (RIGHT - LEFT) + LEFT),
		  (GLfloat)(rand() % (TOP - BOTTOM) + BOTTOM),
		  (GLfloat)(rand() % (RIGHT - LEFT) + LEFT)),
colour((GLfloat)(rand()%255 / 255.0),
       (GLfloat)(rand()%255 / 255.0),
       (GLfloat)(rand()%255 / 255.0),
       (GLfloat)1)
{	
	velocity = glm::vec3((GLfloat)(rand()%9),(GLfloat)(rand()%9),(GLfloat)(rand()%9));
	velocity -= glm::vec3(4, 4, 4);
}

GLfloat Particle::bounds(GLfloat value, GLfloat min, GLfloat max)
{
	if(value <= min)
		return min;
	if(value >= max)
		return max;
	return value;
}

glm::vec3 Particle::bounds(glm::vec3 position)
{
	position.x = bounds(position.x, LEFT, RIGHT);
	position.y = bounds(position.y, BOTTOM, TOP);
	position.z = bounds(position.z, LEFT, RIGHT);

	return position;
}

void Particle::update()
{
	acceleration = glm::vec3(0, 0, 0);

	if(neighbours.size())
	{
		acceleration += alignment() * PARTICLE_ALIGNMENT;
		acceleration += separation() * PARTICLE_SEPARATION;
		acceleration += cohesion() * PARTICLE_COHESION;
		if(Input::isPressed(S))
			acceleration += glm::vec3(0, -1, 0);
		if(Input::isPressed(W))
			acceleration += glm::vec3(0, 1, 0);
	}

	velocity += acceleration;
	if(Input::isPressed(SPACE))
		velocity = glm::normalize(velocity) * PARTICLE_SPEEDBOOST;
	else
		velocity = glm::normalize(velocity) * PARTICLE_SPEED;
	position = bounds(position + velocity);
	//Prepare for next frame
	neighbours.clear();
}

void Particle::draw()
{
	glColor4f(colour.x, colour.y, colour.z, colour.w);
	glRotatef(Input::rotation, 0, 1, 0);
	glTranslatef(position.x, position.y, position.z);

	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Particle::addNeighbour(Particle * neighbour)
{
	neighbours.push_back(neighbour);
}

glm::vec3 Particle::separation()
{
    glm::vec3 divergence = glm::vec3(0, 0, 0);

    for(int index = 0; index < neighbours.size(); index++)
    {
    	float distance = glm::distance(position, neighbours[index]->position);
    	if(distance < PARTICLE_SPACE && distance > 0)
    		divergence += (position - neighbours[index]->position) / distance;
    }

    return divergence - velocity;

}

glm::vec3 Particle::alignment()
{
	glm::vec3 averageDirection = glm::vec3(0, 0, 0);

	for(int index = 0; index < neighbours.size(); index++)
		averageDirection += neighbours[index]->velocity;

	return averageDirection - velocity;
}

glm::vec3 Particle::cohesion()
{
	glm::vec3 center = glm::vec3(0, 0, 0);

	for(int index = 0; index < neighbours.size(); index++)
		center += neighbours[index]->position;
	center /= neighbours.size();

	return (center - position) - velocity;
}

