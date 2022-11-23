#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

//multiplication class -> inherits from operation class
class Multiplication : public Operation
{
    friend class OperationFactory;
protected:
    Multiplication();
    virtual ~Multiplication();

public:
    virtual double compute(double x, double y);
};

#endif // MULTIPLICATION_H
