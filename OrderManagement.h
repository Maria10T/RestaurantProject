#include <iostream>
#include <string>
#include <vector>
#include "Order.h"
#include "Waiter.h"

using namespace std;

#ifndef RESTAURANT_ORDERMANAGEMENT_H
#define RESTAURANT_ORDERMANAGEMENT_H


class OrderManagement {
private:
    vector<Order *> orders;
    vector<Waiter *> waiters;
    static OrderManagement *_instance;

    OrderManagement(const vector<Order *> &orders, const vector<Waiter *> &waiters) : orders(orders),
                                                                                      waiters(waiters) {}

    OrderManagement() {}

    void menu();
public:
    static OrderManagement *getInstance();

    void AddOrder();

    void AddWaiter();

    void OnlineOrderProcentage();

    void DateSummary();

    void BestWaiter();

    void Orders();

    void Waiters();

    void run();

};

#endif //RESTAURANT_ORDERMANAGEMENT_H
