#include "Product.h"

Product::Product() {}

Product::Product(const string &name, float price) : name(name), price(price) {}

Product::~Product() {

}

const string &Product::getName() const {
    return name;
}

float Product::getPrice() const {
    return price;
}

istream &Product::input(istream &in) {
    cout<<"name: ";in>>name;
    cout<<"price: ";in>>price;
    return in;
}

istream &operator>>(istream &in, Product &product){
    return product.input(in);
}

ostream &Product::output(ostream &os) const {
    os<<" name: "<<name;
    os<<" price: "<<price;
    return os;
}

ostream &operator<<(ostream &os, const Product &product){
    return product.output(os);
}