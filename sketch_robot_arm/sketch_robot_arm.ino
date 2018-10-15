#include <Servo.h>

enum EServoPos
{
    JOINT,
    CLAW,
    POS_NUM
};

const char servoPin[POS_NUM] = 
{
    3, // JOINT
    5  // CLAW
};

const int SERVO_MIN[POS_NUM] = {39,  0 }; // {JOINT = uS, CLAW = deg}
const int SERVO_MAX[POS_NUM] = {210, 80}; // {JOINT = uS, CLAW = deg}
const int SERVO_DELAY[POS_NUM] = {2, 15}; // [ms]

Servo armServos[POS_NUM];

void openClaw()
{
    for (int i = SERVO_MAX[CLAW]; i > SERVO_MIN[CLAW]; --i)
    {
        armServos[CLAW].write(i);
        delay(SERVO_DELAY[CLAW]);
    }
}

void closeClaw()
{
    for (int i = SERVO_MIN[CLAW]; i < SERVO_MAX[CLAW]; ++i)
    {
        armServos[CLAW].write(i);
        delay(SERVO_DELAY[CLAW]);
    }
}

void openJoint()
{
    for (int i = SERVO_MIN[JOINT]; i < SERVO_MAX[JOINT]; ++i)
    {
        armServos[JOINT].writeMicroseconds(i*10);
        delay(SERVO_DELAY[JOINT]);
    }
}

void closeJoint()
{
    for (int i = SERVO_MAX[JOINT]; i > SERVO_MIN[JOINT]; --i)
    {
        armServos[JOINT].writeMicroseconds(i*10);
        delay(SERVO_DELAY[JOINT]);
    }
}

void setup()
{
    for (int i = 0; i < POS_NUM; ++i)
    {
        armServos[i].attach(servoPin[i]);
    }
}

void loop()
{
    openClaw();
    delay(200);
    openJoint();
    delay(100);
    closeClaw();
    delay(200);
    closeJoint();
    delay(100);
}
