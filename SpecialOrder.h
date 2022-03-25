#include <iostream>
#include <string>
#include <vector>
#include "Order.h"

using namespace std;

#ifndef RESTAURANT_SPECIALORDER_H
#define RESTAURANT_SPECIALORDER_H

class SpecialOrder: public Order{
private:
    string obs;
    float surcharge;
public:
    SpecialOrder();

    SpecialOrder(const Product &prod, int servingsNo, int day, int month, int year, const string &obs, float surcharge);

    istream &input(istream &in) override;

    ostream &output(ostream &os) const override;

    float OrderValue() override;
};


#endif //RESTAURANT_SPECIALORDER_H
