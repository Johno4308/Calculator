#ifndef OPERATION_H
#define OPERATION_H

// virtual declarations for subclasses, using factory design pattern
class Operation
{
public:
    Operation();
    virtual ~Operation();
    virtual double compute(double x, double y) = 0;
};

#endif // OPERATION_H
