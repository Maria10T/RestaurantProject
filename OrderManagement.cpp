#include "OrderManagement.h"

OrderManagement *OrderManagement::_instance=0;
OrderManagement *OrderManagement::getInstance() {
    if (_instance == nullptr)
        _instance = new OrderManagement;
    return _instance;
}

void OrderManagement::menu() {
    cout<<endl;
    cout << "1. Add Order\n";
    cout << "2. Add Waiter\n";
    cout << "3. Online Order Procentage\n";
    cout << "4. Date Summary\n";
    cout << "5. Best Order\n";
    cout << "6. Display Order\n";
    cout << "7. Display Order\n";
    cout << "0. EXIT\n";
}

void OrderManagement::AddOrder() {
    int opt, valid = 0;
    Order *tempOrder;
    while (!valid) {
        cout << "Enter option: 1-Order, 2-Special Order, 3-Online Order, 4-Online Special Order ";
        cin >> opt;
        valid = 1;
        try {
            if (opt == 1) {
                tempOrder = new Order;
            } else if (opt == 2) {
                tempOrder = new SpecialOrder;
            } else if (opt == 3) {
                tempOrder = new OnlineOrder;
            } else if (opt == 3) {
                tempOrder = new OnlineSpecialOrder;
            } else {
                throw opt;
            }
            tempOrder->input(cin);
            orders.push_back(tempOrder);
        }
        catch (...) {
            cout << "Invalid Option!\n";
            valid = 0;
        }
    }
}
void OrderManagement::AddWaiter() {
    Waiter* tempWaiter = new Waiter;
    tempWaiter->input(cin);
    waiters.push_back(tempWaiter);
}

void OrderManagement::OnlineOrderProcentage() {
    int day, month, year;
    cout<<"Enter Date: ";
    cout<<"Day";
    cin>>day;
    cout<<"Month";
    cin>>month;
    cout<<"Year";
    cin>>year;
    float total=0, onlineTotal=0;
    for(int i=0;i<orders.size();i++)
        if(orders[i]->getDay()== day && orders[i]->getMonth()==month && orders[i]->getYear()==year)
        {
            SpecialOrder *asSpecialOrder =dynamic_cast<SpecialOrder*>(orders[i]);
            Order *asOrder =dynamic_cast<Order*>(orders[i]);
            OnlineOrder *asOnlineOrder =dynamic_cast<OnlineOrder*>(orders[i]);
            OnlineSpecialOrder *asOnlineSpecialOrder =dynamic_cast<OnlineSpecialOrder*>(orders[i]);

            if(asOnlineSpecialOrder != NULL){
                total= total + asOnlineSpecialOrder->OrderValue();
                onlineTotal= onlineTotal + asOnlineSpecialOrder->OrderValue();
            }
            else if(asSpecialOrder != NULL)
                total= total + asSpecialOrder->OrderValue();
            else if(asOnlineOrder != NULL){
                total= total + asOnlineOrder->OrderValue();
                onlineTotal= onlineTotal + asOnlineOrder->OrderValue();
            }
            else if(asOrder != NULL)
                total= total + asOrder->OrderValue();
        }
    float percentage;
    percentage=100*onlineTotal/total;
    cout<<percentage;
}

void OrderManagement::DateSummary() {
    int day, month, year;
    cout<<"Enter Date: ";
    cout<<"Day";
    cin>>day;
    cout<<"Month";
    cin>>month;
    cout<<"Year";
    cin>>year;
    for(int i=0;i<orders.size();i++)
        if(orders[i]->getDay()== day && orders[i]->getMonth()==month && orders[i]->getYear()==year)
            cout<<*orders[i]<<" ";
}

void OrderManagement::BestWaiter() {
    float maxValue=0;
    int waiterNumber=0;
    for(int i=0;i<waiters.size();i++){
        float tempValue=0;
        tempValue=waiters[i]->TotalOrdersValue();
        if(tempValue>maxValue){
            maxValue=tempValue;
            waiterNumber=i;
        }

    }
    cout<<*waiters[waiterNumber];
}

void OrderManagement::Orders() {
    if (orders.empty())
        cout << "No orders registered!\n";

    for (auto &order: orders) {
        cout << *order;
    }
}

void OrderManagement::Waiters() {
    if (waiters.empty())
        cout << "No waiters registered!\n";

    for (auto &waiter: waiters) {
        cout << *waiter;
    }
}

void OrderManagement::run() {
    int option;

    while (true) {
        menu();
        cout << "Enter Option: ";
        cin >> option;
        if (option == 1) {
            AddOrder();
        } else if (option == 2) {
            AddWaiter();
        } else if (option == 3) {
            OnlineOrderProcentage();
        } else if (option == 4) {
            DateSummary();
        } else if (option == 5) {
            BestWaiter();
        } else if (option == 6) {
            Orders();
        } else if (option == 7) {
            Waiters();
        } else if (option==0){
            break;
        } else{
            cout<<"Invalid Option";
        }
    }
}



