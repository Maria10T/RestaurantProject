#include "OnlineSpecialOrder.h"

OnlineSpecialOrder::OnlineSpecialOrder() {}

OnlineSpecialOrder::OnlineSpecialOrder(const Product &prod, int servingsNo, int day, int month, int year,
                                       const string &onlineObs, float onlineSurcharge, const string &onlineAdress,
                                       int onlineComission) : Order(prod, servingsNo, day, month, year),
                                                              onlineObs(onlineObs), onlineSurcharge(onlineSurcharge),
                                                              onlineAdress(onlineAdress),
                                                              onlineComission(onlineComission) {}

istream &OnlineSpecialOrder::input(istream &in) {
    Order::input(in);
    cout<<"Observations: ";
    in>>onlineObs;
    cout<<"Surcharge: ";
    in>>onlineSurcharge;
    cout<<"Shipping adress: ";
    in>>onlineAdress;
    cout<<"Comission: ";
    in>>onlineComission;
    return in;
}

ostream &OnlineSpecialOrder::output(ostream &os) const {
    Order::output(os);
    os<<" Observations: "<<onlineObs;
    os<<" Surcharge: "<<onlineSurcharge;
    os<<" Shipping adress: "<<onlineAdress;
    os<<" Comission: "<<onlineComission;
    return os;
}

float OnlineSpecialOrder::OrderValue() {
    return Order::OrderValue()+onlineSurcharge+onlineComission/100*(Order::OrderValue()+onlineSurcharge);
}
