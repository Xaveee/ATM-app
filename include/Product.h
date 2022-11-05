#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

class Product
{
private:
    int id;
    string name;
    float price;
    int count;

public:
    Product(int id, string name, float price, int count)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->count = count;
    }

    ~Product() {}
};

// Product::Product(int id, string name, float price, int count)
// {
//     this->id = id;
//     this->name = name;
//     this->price = price;
//     this->count = count;
// }

// Customer::~Customer()
// {
// }

#endif