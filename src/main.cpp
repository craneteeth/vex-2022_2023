#include "main.h"
#include <sys/types.h>

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	//setBool(piston2,true);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	//leftGPS();
	//leftNew();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 
void opcontrol()
{ 
	leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	
	std::uint_least32_t now = millis();
	bool pistonValue = false;
	double shooterSpeed = 127;
	int check=1;
	int reverse = 1;
	int longPress = 0;
	int speedIntake = 127;
	bool release = true;
	int checkShoot = 1;
	int checkFeeder = 1;
	int checkColor = 1;
	//setBool(piston2,release);
	while (true) 
	{
		double x = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
		double y = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		double speedDiagonal = sqrt(x*x + y*y);
		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));//left motor
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) );//right motor
		/*runLeftBase(-master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
		runRightBase(-master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));

		if((y>x*2.4 && y>x*-2.4) || (y<x*2.4 && y<x*-2.4)) 
			hexa_move(y);
		else if((y<0.4*x && y>-0.4*x) || (y<-0.4*x && y>0.4*x))
			move_side(x);
		else if((y<2.4*x && y>0.4*x) || (y>2.4*x && y<0.4*x))
			move_diagonal_right(speedDiagonal);
		else if((y<-2.4*x && y>-0.4*x) || (y>-2.4*x && y<-0.4*x))
			move_diagonal_left(speedDiagonal);*/
	
		/*if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //turn left
		{	
			runLeftBase(50);
			runRightBase(-50);
		}
		if (master.get_digital(E_CONTROLLER_DIGITAL_X)) //fast shooting, need calculation74
			shooterSpeed = 90;
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) //slow shooting, need calculation67
			shooterSpeed = 70;
		if (master.get_digital(E_CONTROLLER_DIGITAL_B)) //slow shooting, need calculation63
			shooterSpeed = 60;*/
		/*'
		90-still over maximum distance
		70-higher than medium, but didn't reach maximum
		50- too slow to make even in shortest
		67-midmid distance
		74-mid shooting
		61-shortest
		90 80
		*/
		/*if(master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
		{
			shooterTest();
		}*/
		
		/*if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			checkShoot++;
			delay(300);
		}
		if (checkShoot%2==0)
			shoot(shooterSpeed);
		else
			shoot(0);*/
		if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			check++;
			delay(300);
		}
		if(check%2==0)
			runIntake(127);
		else
		 	runIntake(0);
		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runIntake(-127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
		{
			shoot(-100);
			delay(1200);
			shoot(0);
			delay(300);
		}
		if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			shoot(-100);
		else
			shoot(0);
		/*if(check%2==0&&master.get_digital(E_CONTROLLER_DIGITAL_UP))
			runIntake(-127);
		else if (check%2==0)
			runIntake(127);
		else
			runIntake(0);*/
		/*if (master.get_digital(E_CONTROLLER_DIGITAL_UP))
		{
			reverse++;
			delay(200);
		}
		if(check%2==0 && reverse%2 ==0)
			runIntake(-127);//getting a disc, up button for reverse
		else if(check % 2==0)
			runIntake(127);
		else
			runIntake(0);*/
			
		/*if (checkFeeder%2 ==0 && master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) //piston for shooting
		{
			feeder.move_voltage(-12000);
		}
		else if (checkFeeder%2==0)
			feeder.move_voltage(12000);
		else
			feeder.move_voltage(0);
		if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
		{
			checkFeeder++;
			delay(300);
		} 
		if (master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
		{
			pistonValue = !pistonValue;
			setBool(piston,pistonValue);
			delay(300);
		}
		if(master.get_digital(E_CONTROLLER_DIGITAL_Y))//&&master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) //expanders
		{     
			setBool(piston2,release);
			setBool(piston3,release);
			release = !release;
			delay(200);
		}*/
	}
}

/*
void brake(){
	left_frt.move(0);
	left_bck.move(0);
	right_frt.move(0);
	right_bck.move(0);
}

void intakeBrake(){
	intake_1.move(0);
	intake_2.move(0);
}


void drive(float l, float r){
	left_frt.move(l);
	left_bck.move(l);
	right_frt.move(r);
	right_bck.move(r);
}

void intake(float speed){
	intake_1.move(speed);
	intake_2.move(speed);
}

void flywheel(float speed){
	flywheel_1.move_voltage(speed*(12000.0/127));
	flywheel_2.move_voltage(speed*(12000.0/127));
}

void leftStrafe(float speed){
	left_frt.move(-speed);
	right_bck.move(-speed);
	left_bck.move(speed);
	right_frt.move(speed);
}

void rightStrafe(float speed){
	left_frt.move(speed);
	right_bck.move(speed);
	left_bck.move(-speed);
	right_frt.move(-speed);
}



void MoveBaseTank(){
	float l;
	float r;
	float strafe;
	l = (master.get_analog(ANALOG_LEFT_Y));
	r = (master.get_analog(ANALOG_RIGHT_Y));
	strafe = ((master.get_analog(ANALOG_LEFT_X)));

	if (strafe <= 35 && strafe >= -35){
		drive(l, r);
	}
	else{
		if (strafe <= 35){
			left_frt.move(l+strafe);
			right_bck.move(r+strafe);
			left_bck.move(l-strafe);
			right_frt.move(r-strafe);
			//leftStrafe(-strafe);
		}
		else if (strafe >= 35){
			left_frt.move(l+strafe);
			right_bck.move(r+strafe);
			left_bck.move(l-strafe);
			right_frt.move(r-strafe);
			//rightStrafe(strafe);
		}
		else{ 
			brake();
		}
	}
}

void shoot(int time){
	piston.set_value(true);
	pros::delay(time);
	piston.set_value(false);
}

void TripleShoot(int time){
	piston.set_value(true);
	pros::delay(125);
	piston.set_value(false);
	pros::delay(time);
	piston.set_value(true);
	pros::delay(125);
	piston.set_value(false);
	pros::delay(time);
	piston.set_value(true);
	pros::delay(250);
	piston.set_value(false);
	pros::delay(time);
}

void InchDrive(float target, int speed){
	float x = 0;
	while(x <= target) {
    x = left_bck.get_position()*3.1415*4.0;
	left_frt.move(speed);
	left_bck.move(speed);
    right_frt.move(speed);
	right_bck.move(speed);
    pros::delay(20);
  }
	left_bck.tare_position();
    brake();
}

void InchDriveLeft(float target, int speed){
	float x = 0;
    while(x <= target) {
        //yaw = gyro.get_yaw();
        x = left_bck.get_position()*3.1415*4.0;
        left_frt.move_voltage(-speed*12000/127);
        left_bck.move_voltage(0.95*speed*12000/127);
        right_frt.move_voltage(speed*12000/127);
        right_bck.move_voltage(0.95*-speed*12000/127);
        pros::delay(20);*/
		/*
        if(yaw>=2){
            left_frt.move(-speed*error-(yaw));
            left_bck.move(0.7*speed*error+(yaw));
            right_frt.move(speed*error+(yaw));
            right_bck.move(0.7*-speed*error-(yaw));
		}
		*//*
    }
	left_bck.tare_position();
    brake();
}

void task(float speed, float yaw, float error){

	left_bck.move(speed*yaw+(error*abs(int(yaw))));
    right_frt.move(speed*yaw+(error*abs(int(yaw))));
    right_bck.move(-speed-(error*abs(int(yaw))));
	left_frt.move(-speed-(error*abs(int(yaw))));
	pros::screen::print(pros::E_TEXT_LARGE, 5, "Heading: %3f", gyro.get_yaw());
}



void InchDriveLeft2(float target, int speed){
	float x = 0;
	float yaw = 0;
	float error = 0;
	pros::Task dog{ [speed, yaw, error] {
        while (pros::Task::notify_take(true, TIMEOUT_MAX)) {
            task(speed, yaw, error);
		}}};
    while(x <= target) {
        yaw = gyro.get_yaw();
        x = left_bck.get_position()*3.1415*4.0;
		error = target - x;
        //left_frt.move_voltage(-speed*12000/127);
	    dog.notify();
        if(yaw>=4){
			pros::screen::print(pros::E_TEXT_LARGE, 1, "Correction: %3f", gyro.get_yaw());
			left_bck.move_voltage(0.95*speed*12000/127);
			left_frt.move_voltage(-0.95*speed*12000/127);
			right_frt.move_voltage(speed*12000/127);
			right_bck.move_voltage(-0.95*-speed*12000/127);
			pros::delay(20);
			
        }
    } 
		
	left_bck.tare_position();
    brake();
}


void InchDriveRight(float target, int speed){
	left_frt.tare_position();
    float x = 0;
    while(x <= target) {
        x = left_frt.get_position()*3.1415*4.0;
        left_frt.move_voltage(speed*12000/127);
        left_bck.move_voltage(0.92*-speed*12000/127);
        right_frt.move_voltage(-speed*12000/127);
        right_bck.move_voltage(0.92*speed*12000/127);
        pros::delay(20);
  }
  brake();
}


void InchDriveBck(float target, int speed){
	left_bck.tare_position();
	float x = 0;
	while(x >= -target) {
    x = left_bck.get_position()*3.1415*4.0;
	left_frt.move(-speed);
	left_bck.move(-speed);
    right_frt.move(-speed);
	right_bck.move(-speed);
    pros::delay(20);
  }
    brake();
}

void pidTurn(float target, int time){
	float kp = 1;
	float ki = 0;
	float kd = 0.2;
	float error = 0;
	float errorTotal = 0;
	float errorLast = 0;
	float pTerm = 0;
	float iTerm = 0;
	float dTerm = 0;
	float power = 0;
	for (int i = 0; i < time; i+=20){
		errorLast = error;
		error = target - (gyro.get_yaw());
		errorTotal += error;
		pTerm = error * kp;
		iTerm = ki * errorTotal;
		dTerm = kd * (error - errorLast);
		power = pTerm + iTerm + dTerm;
		left_frt.move(power);
		left_bck.move(power);
		right_frt.move(-power);
		right_bck.move(-power);
		pros::delay(20);
	}
	brake();
}

void FlywheelPID(float target, float speed){;
	float kp = 3.5;
	float ki = 0;
	float kd = 0;
	float error = 0;
	float errorTotal = 0;
	float errorLast = 0;
	float pTerm = 0;
	float iTerm = 0;
	float dTerm = 0;
	float power = speed;
	float currentVelocity = flywheel_1.get_actual_velocity();
	pros::screen::print(pros::E_TEXT_LARGE, 9, "Power: %3f", power);
	if(currentVelocity < 266){
		errorLast = error;
		error = target - (currentVelocity);
		errorTotal += error;
		pTerm = error * kp;
		iTerm = ki * errorTotal;
		dTerm = kd * (error - errorLast);
		power = pTerm + iTerm + dTerm;
		flywheel(power);
		pros::screen::print(pros::E_TEXT_LARGE, 9, "Power: %3f", power);
		pros::delay(50);
	}
	else{
		flywheel(speed);
	}
}

void roll_to_blue(){
	bool keepGoing = true;
	pros::vision_signature_s_t R_ROLLER =
    pros::Vision::signature_from_utility (1, 9517, 10561, 10039, -1163, -497, -830, 1.700, 0);
	vision.set_signature(1, &R_ROLLER);
	while(keepGoing){
		if (vision.get_object_count() > 0){
			intake(0);
			keepGoing = false;
		}
		else{
			intake(-55);
		}
	}
}
void roll_to_red(){
	bool keepGoing = true;
	pros::vision_signature_s_t B_ROLLER =
	pros::Vision::signature_from_utility (2, -3355, -2123, -2739, 6387, 10199, 8293, 2.300, 0);
	vision.set_signature(2, &B_ROLLER);
	while(keepGoing){
		if (vision.get_object_count() > 0){
			intake(0);
			keepGoing = false;
		}
		else{ 
			intake(-55);
		}
	}
}
double distance(double x1, double y1, double x2, double y2)
{
	double xDiff = fabs(x2-x1);
	double yDiff = fabs(y2-y1);
	double d = sqrt(xDiff*xDiff + yDiff*yDiff);
	return d;
}
double angleFromGoal(double x1, double y1, double x2, double y2)//only for <45 degrees
{
	double xDiff = x1 - x2;
	double yDiff = y1 - y2;
	double angle = atan(yDiff/xDiff) * 180 / M_PI;
	return angle;
}
double currentAngle() // only for < 45 degrees
{
	double angle =270 - gps.get_heading();
	return angle;
}
double angleTilted(double angleFromGoal, double currentAngle)
{
	return angleFromGoal - currentAngle;
}
void opcontrol() {
	left_frt.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_bck.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_frt.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_bck.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    double *x;
    double *y;
	bool flywheel_on = true;
	bool intake_on = false;
	piston.set_value(false);
	int pistonDelay = 0;
	double speed = 70;
	//gps.initialize_full(-0.01, 0.2, -1.8, 1.8, 0);
	//flywheel(85);
	pros::Task f_PID{ [] {
        while (pros::Task::notify_take(true, TIMEOUT_MAX)) {
            FlywheelPID(300, 72);
        }
    } };
	while (true) {
		double goal_x = (double)(1800 - 470)/1000;
		double goal_y = (double)(1800  - 470)/1000;  
		double initial_x = (double)(-1800 + 367)/1000;
		double initial_y = (double)(-1800 + 46)/1000;
		double offset_y = -(double)(223 - 46)/1000;
		double offset_x = -(double)3/1000; //367
		//gps.initialize_full(initial_x, initial_y, 0, offset_x, offset_y);	
		double currentX = gps.get_status().x;
		double currentY = gps.get_status().y;
		double angle = currentAngle();
		double d = distance(goal_x, goal_y, currentX, currentY);
		double angleGoal = angleFromGoal(goal_x, goal_y, currentX, currentY);
		double adiff = angleTilted(angleGoal, angle);
		pros::screen::print(pros::E_TEXT_LARGE, 1, "Heading: %3f", gyro.get_heading());
		pros::screen::print(pros::E_TEXT_LARGE, 3, "Flywheel: %3f", flywheel_1.get_actual_velocity());
		pros::screen::print(pros::E_TEXT_LARGE, 5, "Flywheel 2: %3f", flywheel_2.get_actual_velocity());
		pros::screen::print(pros::E_TEXT_LARGE, 7, "Yaw: %3f", gyro.get_yaw());
		MoveBaseTank();
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)))
		{
			speed += 0.5;
			delay(100);
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)))
		{
			speed -= 0.5;
			delay(100);
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)))
		{
			speed += 5;
			delay(100);
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)))
		{
			speed -= 5;
			delay(100);
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))){
			//xpistonDelay += 3;
			std::cout << distance(goal_x, goal_y, currentX, currentY) << " " << 
			speed << " " << angleTilted(angleGoal, angle) << std::endl;
			shoot(130);
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){

		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))){
			if(flywheel_on){
				flywheel(0);
				flywheel_on = false;
			}
			else{
				flywheel(speed);
				flywheel_on = true;
			}
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))){
			speed = 127;
		}
		if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)))
			intake(127);
		else
			intake(0);
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)))
		{
			std::cout <<"O" << std::endl;
			delay(200);
		}
		if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)))
		{
			std::cout << "X" << std::endl;
			std::cout << gps.get_heading() << std::endl;
			std::cout << angleGoal << std::endl;
			std::cout << angleTilted(angleGoal, angle)<<std::endl;
			delay(200);
		}
	}
	pros::delay(20);
}*/

