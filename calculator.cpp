#include "calculator.h"
#include "operation.h"
#include "operationfactory.h"
#include <QHBoxLayout>
#include <QGridLayout>

//main setup of the UI implemented with the constructor
Calculator::Calculator(QWidget *parent) : QWidget(parent),
                                          _xSpinBox{new QDoubleSpinBox},
                                          _ySpinBox{new QDoubleSpinBox},
                                          _displayAnswer{new QLCDNumber},
                                          _clear{new QPushButton("Clear")},
                                          _add{new QPushButton},
                                          _subtract{new QPushButton},
                                          _multiply{new QPushButton},
                                          _divide{new QPushButton},
                                          _close{new QPushButton("Close")},
                                          _logo{new QLabel("Calculator")}
{
    setWindowTitle("Calculator");
    setFixedSize(350, 350);
    _logo->setFixedSize(330, 80);
    _logo->setStyleSheet(" QLabel {"
                         "             font-size: 30px;"
                         "             padding: 12px 28px;"
                         "             border-radius: 12px;"
                         "             border: 2px solid #b29700;"
                         "             font-weight: bold;"
                         "             color: #b29700}");
    _xSpinBox->setFixedSize(155, 35);
    _ySpinBox->setFixedSize(155, 35);
    _add->setFixedSize(155, 35);
    _add->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                        "             border-radius: 12px;"
                        "             border: 2px solid #b29700;}");
    _add->setIcon(QIcon(":/icons/icons/plus.png"));
    _subtract->setFixedSize(155, 35);
    _subtract->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                             "             border-radius: 12px;"
                             "             border: 2px solid #b29700;}");
    _subtract->setIcon(QIcon(":/icons/icons/minus.png"));
    _multiply->setFixedSize(155, 35);
    _multiply->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                                            "             border-radius: 12px;"
                                            "             border: 2px solid #b29700;}");
    _multiply->setIcon(QIcon(":/icons/icons/times.png"));
    _divide->setFixedSize(155, 35);
    _divide->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                         "             border-radius: 12px;"
                         "             border: 2px solid #b29700;}");
    _divide->setIcon(QIcon(":/icons/icons/divide.png"));
    _clear->setFixedSize(155, 35);
    _clear->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                         "             border-radius: 12px;"
                         "             border: 2px solid #b29700;}");
    _clear->setIcon(QIcon(":/icons/icons/clear.png"));
    _close->setFixedSize(155, 35);
    _close->setStyleSheet(" QPushButton {background-color: #F8F6F0;"
                         "             border-radius: 12px;"
                         "             border: 2px solid #b29700;}");
    _close->setIcon(QIcon(":/icons/icons/close.png"));
    _displayAnswer->setFixedSize(330, 50);
    _displayAnswer->setStyleSheet(" QLCDNumber {background-color: #F8F6F0;"
                                  "             font-size: 16px;"
                                  "             text-align: right;"
                                  "             padding: 12px 28px;"
                                  "             border-radius: 12px;"
                                  "             border: 2px solid #b29700;"
                                  "             font-weight: bold;"
                                  "             color: black;}");
    _xSpinBox->setMinimum(-9999);
    _xSpinBox->setMaximum(9999);
    _ySpinBox->setMinimum(-9999);
    _ySpinBox->setMaximum(9999);

    QGridLayout* layout{new QGridLayout};

    layout->addWidget(_logo, 0, 0);

    layout->addWidget(_displayAnswer, 1, 0);
    layout->addWidget(_logo, 0, 0);
    layout->addWidget(_xSpinBox, 2, 0);
    layout->addWidget(_ySpinBox, 3, 0);
    layout->addWidget(_add, 2, 1);
    layout->addWidget(_subtract, 3, 1);
    layout->addWidget(_multiply, 4, 1);
    layout->addWidget(_divide, 5, 1);
    layout->addWidget(_clear, 4, 0);
    layout->addWidget(_close, 5, 0);

    this->setLayout(layout);
    this->adjustSize();


    //buttonAddCylinder->setIcon(QIcon(":/images/cylinder_icon.png"));
    _opFactory = OperationFactory::getInstance();

    _add->setObjectName("add");
    _subtract->setObjectName("subtract");
    _multiply->setObjectName("multiply");
    _divide->setObjectName("divide");

    connect(_add, SIGNAL(clicked()), this, SLOT(handleClicks()));
    connect(_subtract, SIGNAL(clicked()), this, SLOT(handleClicks()));
    connect(_multiply, SIGNAL(clicked()), this, SLOT(handleClicks()));
    connect(_divide, SIGNAL(clicked()), this, SLOT(handleClicks()));
    connect(_clear, SIGNAL(clicked()), this, SLOT(resetGUI()));
    connect(_close, SIGNAL(clicked()), this, SLOT(close()));

}

//deleting of the single instance
Calculator::~Calculator()
{
    _opFactory->deleteInstance();
}

// handling of all 4 maths symbols using a single slot and QObject
void Calculator::handleClicks()
{
    QString op;
    QString obj = QObject::sender()->objectName();
    if (obj == "add") op = "+";
    if (obj == "subtract") op = "-";
    if (obj == "multiply") op = "*";
    if (obj == "divide") op = "/";
    Operation *tempOpr;
    tempOpr = _opFactory->createOperation(op);
    if (tempOpr != nullptr)
    {
        double answer = tempOpr->compute(_xSpinBox->value(), _ySpinBox->value());
        if (qIsNaN(answer)) // division by 0
            _displayAnswer->display("Err");
        else if (QString::number(answer).size() > _displayAnswer->digitCount()) // or use the QLCDNumber::overflow() signal
            _displayAnswer->display("Err");
        else
            _displayAnswer->display(answer);
        delete tempOpr;
    }
    else
        _displayAnswer->display("Err");
}

//slot to clear values
void Calculator::resetGUI()
{
    _xSpinBox->setValue(0.00);
    _ySpinBox->setValue(0.00);
    _displayAnswer->display(0);
}


