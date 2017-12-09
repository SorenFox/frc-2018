#include "WPILib.h"
#include "MyHeader.h"

using namespace frc;

// From MyHeader.h
int add(int a, int b) {
    return a + b;
}

class Robot: public IterativeRobot {
public:

  Talon *left_motor;
  Talon *right_motor;
  int left_motor_port = 1, right_motor_port = 2;

    Robot() { }

    void RobotInit() {
        left_motor = new Talon(left_motor_port);
        right_motor = new Talon(right_motor_port);

        left_motor.Set(1)
        right_motor.Set(2);
      }

    void DisabledInit() {
        right_motor.Set(0);
        left_motor.Set(0);

      }
    void AutonomousInit() { }
    void TeleopInit() { }
    void TestInit() { }

    void DisabledPeriodic() { }
    void AutonomousPeriodic() { }
    void TeleopPeriodic() { }
    void TestPeriodic() { }
};

START_ROBOT_CLASS(Robot)
