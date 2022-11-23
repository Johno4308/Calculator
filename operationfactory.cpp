#include "operation.h"
#include "operationfactory.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"

OperationFactory* OperationFactory::onlyInstance = nullptr;

OperationFactory::OperationFactory()
{
}

OperationFactory* OperationFactory::getInstance()
{
  if(onlyInstance== nullptr)
      onlyInstance = new OperationFactory();
  return onlyInstance;
}

void OperationFactory::deleteInstance()
{
    delete onlyInstance;
}

Operation* OperationFactory::createOperation(QString type)const
{
   if(type == "+")
       return new Addition();
   if(type == "-")
       return new Subtraction();
   if (type == "*")
       return new Multiplication();
   if (type == "/")
       return new Division();
   else return nullptr;
}
