#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDoubleSpinBox>
#include <QLCDNumber>
#include <QPushButton>
#include <QLabel>

class OperationFactory;

//main UI with needed widgets
class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

public slots:
    void resetGUI();     //used to reset doubleSpinBoxes and LCDnumber
    void handleClicks(); //handle multiple clicks in 1 slot using QObject

private:
    OperationFactory *_opFactory;
    QDoubleSpinBox *_xSpinBox;
    QDoubleSpinBox *_ySpinBox;
    QLCDNumber *_displayAnswer;
    QPushButton *_clear;
    QPushButton *_add;
    QPushButton *_subtract;
    QPushButton *_multiply;
    QPushButton *_divide;
    QPushButton *_close;
    QLabel *_logo;
};
#endif // CALCULATOR_H
