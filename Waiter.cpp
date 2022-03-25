#include "Waiter.h"

Waiter::Waiter() {}

Waiter::Waiter(const string &name, char gender, int age, int orderNo, const vector<Order *> &orders) : name(name),
                                                                                                       gender(gender),
                                                                                                       age(age),
                                                                                                       orderNo(orderNo),
                                                                                                       orders(orders) {}

int Waiter::operator>(Waiter w) {
    return orderNo>w.orderNo;
}

int Waiter::operator<(Waiter w) {
    return orderNo<w.orderNo;
}

istream &Waiter::input(istream &in) {
    cout<<"name: ";
    in>>name;
    cout<<"gender: ";
    in>>gender;
    cout<<"age: ";
    in>>age;
    cout<<"orderNo: ";
    in>>orderNo;
    cout<<"Orders: "<<endl;
    for(int i=0;i<orderNo;i++) {
        cout<<"Order "<<i<<" : ";
        int opt;
        Order *tempOrder;

        cout<<"Enter option: 1-Order, 2-Special Order, 3-Online Order, 4-Online Special Order ";
        cin>>opt;
        if(opt==1)
            tempOrder= new Order;
        if(opt==2)
            tempOrder= new SpecialOrder;
        if(opt==3)
            tempOrder= new OnlineOrder;
        if(opt==4)
            tempOrder= new OnlineSpecialOrder;

        tempOrder->input(in);
        orders.push_back(tempOrder);
        cout<<endl;
    }
    return in;
}

istream &operator>>(istream &in, Waiter &waiter){
    return waiter.input(in);
}

ostream &Waiter::output(ostream &os) const {
    os<<"name: "<<name;
    os<<" gender: "<<gender;
    os<<" age: "<<age;
    os<<" orderNo: "<<orderNo;
    os<<" Orders: ";
    int i = 1;
    for (auto &order: orders) {
        os << " Order " << i << " : " << *order<<"\n";
        i++;
    }
    return os;
}

ostream &operator<<(ostream &os, const Waiter &waiter) {
    return waiter.output(os);
}

float Waiter::TotalOrdersValue() {
        float total = 0;
        for (auto &order: orders) {
            total += order->OrderValue();
        }

        return total;

}
