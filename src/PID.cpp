#include "main.h"

PID::PID(double _kP, double _kI, double _kD) {
    kP = _kP;
    kI = _kI;
    kD = _kD;
}

double PID::getError() {
    return error;
}

double PID::setError(double _error) {
    error = _error;
}

double PID::runPID() {
    integral += integrate ? error: 0;
    derivative = error - prevError;
    prevError = error;
    output = (kP * error) + (kI * integral) - (kD * derivative);
    std::cout << output << std::endl;
    return output;
}