#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

//division class -> inherits from operation class
class Division : public Operation
{
    friend class OperationFactory;
protected:
    Division();
    virtual ~Division();

public:
    virtual double compute(double x, double y);
};


#endif // DIVISION_H
