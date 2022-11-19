// Name
// Billy Brooks
// Anh Minh Nhat Doan
// Huy Huynh
// Hung Nguyen

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <map>
#include "Customer.h"
#include "Product.h"

using namespace std;

struct gen_data
{
    float reward_ratio;
    float redeem_ratio;
    int max_rtid;
    int max_stid;
};

// PREPROCESSING
void read_cust_to_vect(string file_name, vector<Customer> &vect);
void write_to_cust(string file_name, vector<Customer> vect);
void read_prod_to_vect(string file_name, vector<Product> &vect);
void write_to_prod(string file_name, vector<Product> vect);

// SAVING AND LOADING RATIO AND MAX TRANSACTION ID
void get_general(string file_name, gen_data &g_dat);
void save_general(string file_name, gen_data g_dat);

// FIND CUSTOMER/PRODUCT BY ID
int find_cust_by_id(vector<Customer> &vect, string action);
int find_prod_by_id(vector<Product> &vect, string action);
// string id_generator(string max_id, string header, int body_length);

// ADD CUSTOMER/PRODUCT
void cust_registration(vector<Customer> &vect);
void prod_registration(vector<Product> &vect);

// In validation.cpp
int input_prod_description(string &description);
int input_prod_price(float &price);
int input_prod_stock(int &in_stock);
int input_username(string &username, vector<Customer> vect);
int input_name(string &name, string type);
int input_dob(string &dob);
int input_cred_num(string &cred_num, vector<Customer> vect);
int input_reward_point(float &point);
float input_ratio(string type);

// CHANGE RATIO
void change_ratio(string gen_file, gen_data &g_dat, string type);

// REDEEM PRODUCT
void redeem_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, string gen_file, string r_transact_file, gen_data &g_dat);
void display_redeem_product(vector<Product> &prod_vect, float redeem_ratio);
void display_shop_product(vector<Product> &prod_vect);
int redeem_transaction(vector<Product> &prod_vect, Customer &cust, string gen_file, string r_transact_file, gen_data &g_dat);

// SAVE TO TRANSACTION LOG FILE
void append_to_r_transact(string file_name, int &max_tid, string cust_id, string prod_id, float prod_price, float prod_point);
void append_to_s_transact(string file_name, map<int, int> &shop_cart, Customer cust, vector<Product> vect, gen_data &g_dat);

// SHOPPING
void shop_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, string gen_file, string file_name, gen_data &g_dat);
int add_to_cart(map<int, int> &shop_cart, vector<Product> &prod_vect);
float print_cart(map<int, int> &shop_cart, vector<Product> &prod_vect);

#endif