#ifndef INPUT_H
#define INPUT_H

#define ROTATION 1

//The Keys definitions
enum Keys
{
    W,
    A,
    S,
    D,
    SPACE,
    C,
    NUMBER_OF_KEYS
};

class Input
{
    public:
    	//The rotation of the camera (TODO: To be moved in the camera class)
        static double rotation;
        //Return if the key is pressed
        static bool isPressed(Keys key);
        //Handle for key down event
        static void keyDown(unsigned char key, int x, int y);
        //Handle for key up event
        static void keyUp(unsigned char key, int x, int y);
    private:
        //Keys map
        static bool keys[NUMBER_OF_KEYS];
};

#endif // INPUT_H
