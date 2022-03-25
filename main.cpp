#include <iostream>
#include "OrderManagement.h"
using namespace std;

int main() {
    OrderManagement *app = OrderManagement::getInstance();
    app->run();



    return 0;
}
