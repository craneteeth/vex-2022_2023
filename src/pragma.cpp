#include "main.h"
using namespace pros;

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor leftBase1(3, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBase2(2, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase1(4, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase2(1  , pros::E_MOTOR_GEARSET_18,1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor shooter1(11, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor shooter2(16, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor shooter3(17, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake(5, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake2(6, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor feeder(8, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIDigitalOut piston('A');
pros::ADIDigitalOut piston2('B');
pros::ADIDigitalOut piston3('C');
GPS gps(21,-1,-1.7,0);
Vision vision(1);
Imu gyro_turret(8);
Imu gyro_base(1);
/*Controller master(pros::E_CONTROLLER_MASTER);
ADIDigitalOut piston('E', false);
ADIDigitalOut expansion('B', false);
Motor left_frt(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor left_bck(11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor right_frt(20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor right_bck(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor flywheel_1(4, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor flywheel_2(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor intake_1(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
Motor intake_2(7, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
Gps gps(16);
Imu gyro(9);
Vision vision (16);*/