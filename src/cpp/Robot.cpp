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
  RobotDrive *my_robot;
  XboxController *xbox;
  LiveWindow *lw;
  int left_motor_port = 1, right_motor_port = 2;

    Robot() { }

    void RobotInit() {
      left_motor = new Talon(left_motor_port);
      right_motor = new Talon(right_motor_port);

      my_robot = new RobotDrive(left_motor, right_motor);

      xbox = new XboxController(1);

      lw = LiveWindow::GetInstance();

    }

    void DisabledInit() {
      my_robot->TankDrive(0.0,0.0);

    }
    void AutonomousInit() { }
    void TeleopInit() { }
    void TestInit() { }

    void DisabledPeriodic() { }
    void AutonomousPeriodic() { }
    void TeleopPeriodic() {
      my_robot->TankDrive(xbox->GetRawAxis(2),xbox->GetRawAxis(5),true);
    }
    void TestPeriodic() {
      lw->Run();
    }
};

START_ROBOT_CLASS(Robot)
