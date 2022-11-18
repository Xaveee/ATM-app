#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <map>
#include "Customer.h"
#include "Product.h"

using namespace std;

// PREPROCESSING
void read_cust_to_vect(string file_name, vector<Customer> &vect);
void write_to_cust(string file_name, vector<Customer> vect);
void read_prod_to_vect(string file_name, vector<Product> &vect);
void write_to_prod(string file_name, vector<Product> vect);

// SAVING AND LOADING RATIO AND MAX TRANSACTION ID
void get_general(string file_name, float &reward_ratio, float &redeem_ratio, int &max_rtid);
void save_general(string file_name, float reward_ratio, float redeem_ratio, int max_rtid);
void get_shopping_config(int &max_stid, string file_name);
void save_shopping_config(string config_file, int max_tid);

// FIND CUSTOMER/PRODUCT BY ID
int find_cust_by_id(vector<Customer> &vect, string action);
int find_prod_by_id(vector<Product> &vect, string action);
// string id_generator(string max_id, string header, int body_length);

// ADD CUSTOMER/PRODUCT
void cust_registration(vector<Customer> &vect);
void prod_registration(vector<Product> &vect);
int input_prod_description(string &description);
int input_prod_price(float &price);
int input_prod_stock(int &in_stock);
int input_username(string &username, vector<Customer> vect);
int input_name(string &name, string type);
int input_dob(string &dob);
int input_cred_num(string &cred_num, vector<Customer> vect);
int input_reward_point(float &point);

// CHANGE RATIO
void change_reward_ratio(string gen_file, float &reward_ratio, float redeem_ratio, int max_rtid);
void change_redeem_ratio(string gen_file, float reward_ratio, float &redeem_ratio, int max_rtid);
float input_ratio(string type);

// REDEEM PRODUCT
void redeem_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid);
void display_redeem_product(vector<Product> &prod_vect, float redeem_ratio);
void display_shope_product(vector<Product> &prod_vect);
int redeem_transaction(vector<Product> &prod_vect, vector<Customer> &cust_vect, int &prod_index, int &cust_index, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid);

// SAVE TO TRANSACTION LOG FILE
void append_to_r_transact(string file_name, int &max_tid, string cust_id, string prod_id, float prod_price, float prod_point);
void append_to_s_transact(string config_file, string file_name, int max_tid, map<int, int> &shop_cart, Customer cust, vector<Product> vect, float reward_ratio);

// SHOPPING
void shop_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float reward_ratio, int &max_tid, string config_file, string file_name);
int add_to_cart(map<int, int> &shop_cart, vector<Product> &prod_vect);
float print_cart(map<int, int> &shop_cart, vector<Product> &prod_vect);

#endif