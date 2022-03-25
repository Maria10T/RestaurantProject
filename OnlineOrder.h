#include <iostream>
#include "Order.h"

using namespace std;

#ifndef RESTAURANT_ONLINEORDER_H
#define RESTAURANT_ONLINEORDER_H

class OnlineOrder: public Order {
private:
    string adress;
    int comission;
public:
    OnlineOrder();

    OnlineOrder(const Product &prod, int servingsNo, int day, int month, int year, const string &adress, int comission);

    istream &input(istream &in) override;

    ostream &output(ostream &os) const override;

    float OrderValue() override;
};


#endif //RESTAURANT_ONLINEORDER_H
