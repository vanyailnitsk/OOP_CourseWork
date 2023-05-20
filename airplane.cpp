#include "airplane.h"

Airplane::Airplane() {
    number = QString();
    direction =  QString();
    depTime = QString();
    type = QString();
    seats = QString();
}
Airplane::Airplane(Airplane & src) {
    number = src.number;
    direction = src.direction;
    depTime = src.depTime;
    seats = src.seats;
    type = src.type;
}
Airplane::Airplane(QString number1,QString direction1,QString depTime1,QString seats1,QString type1) {
    number = number1;
    direction = direction1;
    depTime =  depTime1;
    seats = seats1;
    type = type1;
}
QString Airplane::getNumber() {
    return number;
}
QString Airplane::getDirection() {
    return direction;
}
QString Airplane::getDepTime() {
    return depTime;
}
QString Airplane::getType() {
    return type;
}
QString Airplane::getSeats() {
    return seats;
}
