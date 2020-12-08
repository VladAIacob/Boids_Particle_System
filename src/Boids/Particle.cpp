#pragma once
#include <stdlib.h>
#include "Particle.h"
#include <iostream>
Particle::Particle()
:position((GLfloat)(rand() % RIGHT + LEFT), (GLfloat)(rand() % TOP + BOTTOM), (GLfloat)(rand() % RIGHT + LEFT)),
colour((GLfloat)(rand()%255 / 255.0), (GLfloat)(rand()%255 / 255.0), (GLfloat)(rand()%255 / 255.0), (GLfloat)1)
{
	force = glm::vec3((GLfloat)(rand()%3),(GLfloat)(rand()%3),(GLfloat)(rand()%3));
	force /= 100.0;
	//force = glm::normalize(glm::vec3(rand(), rand(), rand())) * SPEED;
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
	separation();
	alignment();
	cohesion();

	position = bounds(position + force);
	//Prepare for next frame
	neighbours.clear();
}

void Particle::draw()
{
	glColor4f(colour.x, colour.y, colour.z, colour.w);
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

void Particle::separation()
{
}

void Particle::alignment()
{
}

void Particle::cohesion()
{
}

