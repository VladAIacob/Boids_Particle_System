#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once
#include <vector>
#include "../include.h"

#define BOTTOM -5
#define TOP 5
#define LEFT -5
#define RIGHT 5

#ifndef PARTICLE_PROPRIETIES
    #define PARTICLE_PROPRIETIES
    #define PARTICLE_SIGHT 1.0f
    #define PARTICLE_SPACE 0.5f
    #define PARTICLE_SPEED 0.1f
    #define PARTICLE_SEPARATION 1.5f
    #define PARTICLE_ALIGNMENT 1.0f
    #define PARTICLE_COHESION 0.01f
#endif

class Particle
{
    public:
        glm::vec3 position;
        glm::vec3 velocity;
        glm::vec3 acceleration;

        glm::vec4 colour;

        Particle();
        void update();
        void draw();
        void addNeighbour(Particle * neighbour);

    private:
    	std::vector<Particle *> neighbours;

        GLfloat bounds(GLfloat value, GLfloat min, GLfloat max);
        glm::vec3 bounds(glm::vec3 position);

        glm::vec3 separation();
        glm::vec3 alignment();
        glm::vec3 cohesion();
};

#endif // PARTICLE_H
