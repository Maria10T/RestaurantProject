#include <iostream>
#include <string>
#include <vector>
#include "Order.h"


using namespace std;

#ifndef RESTAURANT_ONLINESPECIALORDER_H
#define RESTAURANT_ONLINESPECIALORDER_H

class OnlineSpecialOrder: public Order {
private:
string onlineObs;
float onlineSurcharge;
string onlineAdress;
int onlineComission;
public:
    OnlineSpecialOrder();

    OnlineSpecialOrder(const Product &prod, int servingsNo, int day, int month, int year, const string &onlineObs,
                       float onlineSurcharge, const string &onlineAdress, int onlineComission);

    istream &input(istream &in) override;

    ostream &output(ostream &os) const override;

    float OrderValue() override;

};


#endif //RESTAURANT_ONLINESPECIALORDER_H
