# Boids_Particle_System
A simple particle system simulating boid behaviour. It uses GLUT, GLEW and the glm library.
This particle system is not optimised to perform better with the GPU. Currently, it uses array buffers to draw the voxel particles.

# To build the project 
run 'make' or 'make all'.

# To start the engine 
run the executable build/main.

# INPUT
[A, D] rotates the camera clockwise/counter-clockwise

[S, W] adds a down/up force to each particle

[C] changes the colour of all particles

[Space] switches the particles' speed from normal to boost

[ESC] closes the engine 
