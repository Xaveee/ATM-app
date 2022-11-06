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

string Customer::get_username()
{
    return username;
}

string Customer::get_fname()
{
    return first_name;
}

string Customer::get_lname()
{
    return last_name;
}

string Customer::get_dob()
{
    return dob;
}

string Customer::get_cred_num()
{
    return cred_num;
}

float Customer::get_point()
{
    return total_points;
}