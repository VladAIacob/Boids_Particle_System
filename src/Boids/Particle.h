#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once
#include <vector>
#include "../include.h"

//The dimensions of the enclosure
#define BOTTOM -5
#define TOP 5
#define LEFT -5
#define RIGHT 5

//Particles' proprieties
#ifndef PARTICLE_PROPRIETIES
    #define PARTICLE_PROPRIETIES

    #define PARTICLE_SIGHT 1.0f
    #define PARTICLE_SPACE 0.5f

    #define PARTICLE_SPEED 0.1f
    #define PARTICLE_SPEEDBOOST 0.2f

    #define PARTICLE_SEPARATION 1.5f
    #define PARTICLE_ALIGNMENT 1.0f
    #define PARTICLE_COHESION 0.01f
#endif

class Particle
{
    public:
        //Physics variables to handle movement
        glm::vec3 position;
        glm::vec3 velocity;
        glm::vec3 acceleration;

        //Colour of the particle
        glm::vec4 colour;

        Particle();

        //Method to update the particle's position and movement
        void update();
        //Method to draw the particle(TODO: change to vbo)
        void draw();
        //Method to add a particle to a list of 'neighbours' representing the closest particles
        void addNeighbour(Particle * neighbour);

    private:
        //A vector of local flockmates in sight
        //Updated and cleared every frame
    	std::vector<Particle *> neighbours;

        //Helper methods to bound the position to the enclosure
        GLfloat bounds(GLfloat value, GLfloat min, GLfloat max);
        glm::vec3 bounds(glm::vec3 position);

        //Boid basic movement and behaviour
        glm::vec3 separation(); //Steer to avoid crowding local flockmates
        glm::vec3 alignment();  //Steer towards the average heading of local flockmates
        glm::vec3 cohesion();   //Steer to move towards the center of mass of local flockmates
};

#endif // PARTICLE_H
