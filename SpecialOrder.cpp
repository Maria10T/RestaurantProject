#include "SpecialOrder.h"


SpecialOrder::SpecialOrder() {}

SpecialOrder::SpecialOrder(const Product &prod, int servingsNo, int day, int month, int year, const string &obs,
                           float surcharge) : Order(prod, servingsNo, day, month, year), obs(obs),
                                              surcharge(surcharge) {}

istream &SpecialOrder::input(istream &in) {
   Order::input(in);
    cout<<"Observations: ";
    in>>obs;
    cout<<"Surcharge: ";
    in>>surcharge;
    return in;
}

ostream &SpecialOrder::output(ostream &os) const {
    Order::output(os);
    os<<" Observations: "<<obs;
    os<<" Surcharge: "<<surcharge;
    return os;
}

float SpecialOrder::OrderValue() {
    return Order::OrderValue()+surcharge;
}
