#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once
#include <vector>
#include "../include.h"

#define SPEED 0.5
#define BOTTOM -5
#define TOP 5
#define LEFT -5
#define RIGHT 5

class Particle
{
    public:
        glm::vec3 position;
        glm::vec3 force;
        glm::vec4 colour;

        Particle();
        void update();
        void draw();
        void addNeighbour(Particle * neighbour);

    private:
    	std::vector<Particle *> neighbours;

        GLfloat bounds(GLfloat value, GLfloat min, GLfloat max);
        glm::vec3 bounds(glm::vec3 position);

        void separation();
        void alignment();
        void cohesion();
};

#endif // PARTICLE_H
