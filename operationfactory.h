#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

class Operation;

#include <QString>

//class implementation for singleton design pattern.
//calling limited to a single instance of an object
class OperationFactory
{
public:
    Operation* createOperation(QString type) const;
    static OperationFactory* getInstance();
    static void deleteInstance();

private:
    OperationFactory();
    static OperationFactory* onlyInstance;
};

#endif // OPERATIONFACTORY_H
