#include <iostream>

#include "../include/Customer.h"
using namespace std;

void Customer::show_cust()
{
    cout << id << endl
         << username << endl
         << first_name << endl
         << last_name << endl
         << dob << endl
         << total_points << endl;
}

string Customer::get_id()
{
    return id;
}