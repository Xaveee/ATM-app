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

string Product::get_name()
{
    return name;
}

float Product::get_price()
{
    return price;
}

int Product::get_count()
{
    return count;
}
void Product::set_count(float n_count)
{
    count = n_count;
}