#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

#ifndef RESTAURANT_ORDER_H
#define RESTAURANT_ORDER_H

class Order {
protected:
    static int lastid;
    int id;
    Product prod;
    int servingsNo;
    int day{};
    int month{};
    int year{};
public:
    Order();

    Order(const Product &prod, int servingsNo, int day, int month, int year);

    virtual ~Order();

    virtual Order operator + (int x);

    virtual Order operator ++ (int);

    virtual istream &input(istream &in);
    friend istream &operator>>(istream &in, Order &order);

    virtual ostream &output(ostream &os) const;
    friend ostream &operator<<(ostream &os, const Order &order);

    virtual void del();

    virtual float OrderValue ();

    int getDay() const;

    int getMonth() const;

    int getYear() const;
};


#endif //RESTAURANT_ORDER_H
