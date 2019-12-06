using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor RearRight;
extern motor FrontRight;
extern motor FrontLeft;
extern motor RearLeft;
extern motor LeftDump;
extern motor RightDump;
extern motor RightIntake;
extern motor LeftIntake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );