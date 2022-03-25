#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef RESTAURANT_PRODUCT_H
#define RESTAURANT_PRODUCT_H

class Product {
    string name;
    float price;
public:
    Product();

    Product(const string &name, float price);

    virtual ~Product();

    const string &getName() const;

    float getPrice() const;

    virtual istream &input(istream &in);
    friend istream &operator>>(istream &in, Product &product);

    virtual ostream &output(ostream &os) const;
    friend ostream &operator<<(ostream &os, const Product &product);

};


#endif //RESTAURANT_PRODUCT_H
