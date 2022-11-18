#include <iostream>

#include "../include/Customer.h"
using namespace std;

void Customer::show_cust()
{
    cout << "\nCustomer ID: " << id << endl
         << "Customer Username: " << username << endl
         << "Customer First Name: " << first_name << endl
         << "Customer Last Name: " << last_name << endl
         << "Customer Date of Birth: " << dob << endl
         << "Customer Reward Point: " << fixed << total_points << endl
         << endl;
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

void Customer::set_point(float n_point)
{
    total_points = n_point;
}