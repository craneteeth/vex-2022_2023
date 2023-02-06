#ifndef PID_H
#define PID_H
class PID {
    private:
        double error, integral, derivative, prevError, kP, kI, kD, output;
        bool integrate;
    public:
        PID(double _kP, double _kI, double _kD);
        double getError();
        double setError(double _error);
        double runPID();
};
#endif