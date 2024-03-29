// Name
// Billy Brooks
// Anh Minh Nhat Doan
// Huy Huynh
// Hung Nguyen

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

//***************************************************************
// Customer class
// Contains data of one customer, including:
//      - ID (unique)
//      - Username (unique)
//      - First and last name
//      - Date of birth
//      - Credit card number (unique)
//      - Reward point
//***************************************************************
class Customer
{
private:
    string id;
    string username;
    string first_name;
    string last_name;
    string dob;
    string cred_num;
    float total_points;

public:
    Customer(string id = 0,
             string username = "",
             string first_name = "",
             string last_name = "",
             string dob = 0,
             string cred_num = "",
             float total_points = 0)
    {
        this->id = id;
        this->username = username;
        this->first_name = first_name;
        this->last_name = last_name;
        this->dob = dob;
        this->cred_num = cred_num;
        this->total_points = total_points;
    }

    ~Customer() {}

    void show_cust();
    string get_id();
    string get_username();
    string get_fname();
    string get_lname();
    string get_dob();
    string get_cred_num();
    float get_point();
    void set_point(float n_point);
};

// Customer::~Customer()
// {
// }

#endif