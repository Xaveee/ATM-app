#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

class Product
{
private:
    string id;
    string name;
    float price;
    int count;

public:
    Product(string id, string name, float price, int count)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->count = count;
    }

    ~Product() {}

    void show_prod();
    string get_id();
    string get_name();
    float get_price();
    int get_count();
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