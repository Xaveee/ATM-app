// Name
// Billy Brooks
// Anh Minh Nhat Doan
// Huy Huynh
// Hung Nguyen

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

//***************************************************************
// Product class
// Contains data of one product, including:
//      - ID (unique)
//      - Description
//      - Price
//      - Number of items left in stock
//***************************************************************
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
    void set_count(float n_count);
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