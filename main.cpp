#include <iostream>
#include <fstream>
#include <vector>

#include "include/Customer.h"
#include "include/Product.h"
#include "include/util.h"

using namespace std;

int main()
{
    cout << "Customer Reward System\n\n";

    // 1. Read customer and product save file
    vector<Customer> cust_vect;
    vector<Product> prod_vect;

    // 2. Save data to vectors for processing
    read_cust_to_vect("customers.txt", cust_vect);
    // read_prod_to_vect("products.txt", prod_vect);

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
        cout << "0. Exit.\n";

        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << choice << endl;
            break;
        case 2:
            cout << choice << endl;
            break;
        case 3:
            cout << choice << endl;
            break;
        case 4:
            cout << choice << endl;
            break;
        case 5:
            cout << choice << endl;
            break;
        case 6:
            show_cust_by_id(cust_vect);
            break;
        case 7:
            cout << choice << endl;
            break;

        default:
            cout << "Invalid option";
            break;
        }
    } while (choice != 0);
}