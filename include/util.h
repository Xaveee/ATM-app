#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"

using namespace std;

void read_cust_to_vect(string file_name, vector<Customer> &vect);
void write_to_cust(string file_name, vector<Customer> vect);
void read_prod_to_vect(string file_name, vector<Product> &vect);
void find_cust_by_id(vector<Customer> &vect, string action);
void show_prod_by_id(vector<Product> &vect);
void cust_registration(vector<Customer> &vect);
int input_username(string &username, vector<Customer> vect);
int input_name(string &name, string type);
int input_dob(string &dob);
int input_cred_num(string &cred_num, vector<Customer> vect);
int input_reward_point(float &point);
#endif