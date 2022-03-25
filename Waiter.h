#include <iostream>
#include <string>
#include <vector>
#include "SpecialOrder.h"
#include "OnlineOrder.h"
#include "OnlineSpecialOrder.h"
using namespace std;

#ifndef RESTAURANT_WAITER_H
#define RESTAURANT_WAITER_H


class Waiter{
private:
    string name;
    char gender;
    int age;
    int orderNo;
    vector<Order*> orders;
public:
    Waiter();

    Waiter(const string &name, char gender, int age, int orderNo, const vector<Order *> &orders);

    virtual int operator > (Waiter w);

    virtual int operator < (Waiter w);

    virtual istream &input(istream &in);
    friend istream &operator>>(istream &in, Waiter &waiter);

    virtual ostream &output(ostream &os) const;
    friend ostream &operator<<(ostream &os, const Waiter &waiter);

    float TotalOrdersValue();

};


#endif //RESTAURANT_WAITER_H
