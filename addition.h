#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"

//addtion class -> inherits from operation class
class Addition : public Operation
{
    friend class OperationFactory;
protected:
    Addition();
    virtual ~Addition();

public:
    virtual double compute(double x, double y);
};

#endif // ADDITION_H
