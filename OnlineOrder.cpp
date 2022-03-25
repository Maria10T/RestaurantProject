#include "OnlineOrder.h"


OnlineOrder::OnlineOrder() {}

OnlineOrder::OnlineOrder(const Product &prod, int servingsNo, int day, int month, int year, const string &adress,
                         int comission) : Order(prod, servingsNo, day, month, year), adress(adress),
                                          comission(comission) {}

istream &OnlineOrder::input(istream &in) {
   Order::input(in);
    cout<<"Shipping adress: ";
    in>>adress;
    cout<<"Comission: ";
    in>>comission;
    return in;
}

ostream &OnlineOrder::output(ostream &os) const {
    Order::output(os);
    os<<" Shipping adress: ";
    os<<adress<<" Comission: "<<comission;
    return os;
}

float OnlineOrder::OrderValue() {
    return Order::OrderValue()+comission/100*Order::OrderValue();
}
