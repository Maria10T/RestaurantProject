#include "Order.h"



int Order::lastid =1;

Order::Order() {}

Order::Order(const Product &prod, int servingsNo, int day, int month, int year) : id(lastid++), prod(prod),
                                                                                      servingsNo(servingsNo), day(day),
                                                                                      month(month), year(year) {}

Order::~Order() {

}

Order Order::operator+(int x) {
    servingsNo=servingsNo+x;
    return *this;
}

Order Order::operator++(int) {
    servingsNo++;
    return *this;
}

istream &Order::input(istream &in) {
    cout<<"Unique ID: ";
    in>>id;
    cout<<"Product: "<<endl;
    in>>prod;
    cout<<"Number of servings: ";
    in>>servingsNo;
    cout<<"Date: "<<endl;
    cout<<"Day: ";
    in>>day;
    cout<<"Month: ";
    in>>month;
    cout<<"Year: ";
    in>>year;
    return in;
}

istream &operator>>(istream &in, Order &order){
    return order.input(in);
}

ostream &Order::output(ostream &os) const {
    os<<"Unique ID: "<<id;
    os<<" Product: ";
    os<<prod;
    os<<" Number of servings: "<<servingsNo;
    os<<" Date: ";
    os<<" Day: "<<day;
    os<<" Month: "<<month;
    os<<" Year: "<<year;
    return os;
}

ostream &operator<<(ostream &os, const Order &order) {
    return order.output(os);
}

void Order::del() {
    prod={};
    servingsNo=0;
    cout<<"Order canceled";
}

float Order::OrderValue() {
    return prod.getPrice()*float(servingsNo);
}

int Order::getDay() const {
    return day;
}

int Order::getMonth() const {
    return month;
}

int Order::getYear() const {
    return year;
}
