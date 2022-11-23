#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "operation.h"

//subtraction class -> inherits from operation class
class Subtraction : public Operation
{
    friend class OperationFactory;
protected:
    Subtraction();
    virtual ~Subtraction();

public:
    virtual double compute(double x, double y);
};

#endif // SUBTRACTION_H
