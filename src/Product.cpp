#include <iostream>

#include "../include/Product.h"
using namespace std;

void Product::show_prod()
{
    cout << id << endl
         << name << endl
         << price << endl
         << count << endl;
}

string Product::get_id()
{
    return id;
}