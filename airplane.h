#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <QString>
#include <QTime>
#include <QTableWidgetItem>
class Airplane
{
private:
    QString number;
    QString direction;
    QString depTime;
    QString seats;
    QString type;

public:
    Airplane(QString number1,QString direction1,QString depTime1,QString seats1,QString type1);
    Airplane();
    Airplane (Airplane & src);
    QString getNumber();
    QString getDirection();
    QString getDepTime();
    QString getSeats();
    QString getType();
};

#endif // AIRPLANE_H
