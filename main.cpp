#include <iostream>
#include <fstream>
#include <vector>

#include "include/Customer.h"
#include "include/Product.h"
#include "include/util.h"
// #include "include/Rewardmanagement.h"

using namespace std;

int main()
{
    // FILE NAMES
    string cust_file = "customers.txt";
    string prod_file = "products.txt";
    string gen_file = "general.txt";
    string r_transact_file = "redeem_transactions.txt";

    string config_file_name = "config.txt";
    string transact_file = "transactions.txt";

    // 1. Read customer and product save file
    vector<Customer> cust_vect;
    vector<Product> prod_vect;

    gen_data g_dat;

    // Preprocessing
    get_general(gen_file, g_dat);

    // 2. Save data to vectors for processing
    read_cust_to_vect(cust_file, cust_vect);
    read_prod_to_vect(prod_file, prod_vect);

    int choice;
    do
    {
        cout << "Choose your options\n";
        cout << "1. Customer registration.\n";
        cout << "2. Customer Removal.\n";
        cout << "3. Product addition.\n";
        cout << "4. Product removal.\n";
        cout << "5. Shopping.\n";
        cout << "6. View customer using customer ID.\n";
        cout << "7. Redeem rewards.\n";
        cout << "8. Change reward ratio.\n";
        cout << "9. Change redeem ratio.\n";
        cout << "0. Exit.\n";

        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cust_registration(cust_vect);
            write_to_cust(cust_file, cust_vect);
            break;
        case 2:
            find_cust_by_id(cust_vect, "delete");
            write_to_cust(cust_file, cust_vect);
            break;
        case 3:
            cin.ignore(); // cin weird behavior. DO NOT DELETE.
            prod_registration(prod_vect);
            write_to_prod(prod_file, prod_vect);
            break;
        case 4:
            find_prod_by_id(prod_vect, "delete");
            write_to_prod(prod_file, prod_vect);
            break;
        case 5:
            // cout << choice << endl;
            shop_prod(prod_vect, cust_vect, gen_file, transact_file, g_dat);
            write_to_cust(cust_file, cust_vect);
            write_to_prod(prod_file, prod_vect);

            break;
        case 6:
            find_cust_by_id(cust_vect, "show");
            // show_prod_by_id(prod_vect);
            break;
        case 7:
            redeem_prod(prod_vect, cust_vect, gen_file, r_transact_file, g_dat);
            write_to_cust(cust_file, cust_vect);
            write_to_prod(prod_file, prod_vect);

            break;
        case 8:
            // Rewardmanagement(cust_vect);
            change_ratio(gen_file, g_dat, "reward");
            break;
        case 9:
            change_ratio(gen_file, g_dat, "redeem");
            break;

        default:
            cout << "Invalid option";
            break;
        }
    } while (choice != 0);
}