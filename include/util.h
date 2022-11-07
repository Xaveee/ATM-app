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
void write_to_prod(string file_name, vector<Product> vect);
void find_cust_by_id(vector<Customer> &vect, string action);
void find_prod_by_id(vector<Product> &vect, string action);
void cust_registration(vector<Customer> &vect);
void prod_registration(vector<Product> &vect);
int input_prod_description(string &description);
int input_prod_price(float &price);
int input_prod_stock(int &in_stock);
string id_generator(string max_id, string header, int body_length);
int input_username(string &username, vector<Customer> vect);
int input_name(string &name, string type);
int input_dob(string &dob);
int input_cred_num(string &cred_num, vector<Customer> vect);
int input_reward_point(float &point);
#endif