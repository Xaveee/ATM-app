#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"

using namespace std;

void read_cust_to_vect(string file_name, vector<Customer> &vect);
void read_prod_to_vect(string file_name, vector<Product> &vect);
void show_cust_by_id(vector<Customer> &vect);
#endif