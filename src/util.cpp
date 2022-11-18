#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <map>

#include "../include/Customer.h"
#include "../include/Product.h"
#include "../include/util.h"
#include "validation.cpp"

using namespace std;

// ******************************************************************************
// Function Name:   parse_line()
// Parameter:       a string containing multiple words separated by spaces
// Return:          the last word in the string
// Description:     Function used to get the actual data from lines in text files
// ******************************************************************************
string parse_line(string line)
{
    int index;
    index = line.find_last_of(" ") + 1;
    // cout << line.substr(index, line.length() - 1) << endl;
    return line.substr(index, line.length() - 1);
}

// ******************************************************************************
// Function Name:   id_generator
// Parameter:       a string containing the current "maximum" ID, the ID's header
//                  and the number of digits after the header
// Return:          the next unique ID
// Description:     Function used to generate ID for customer, product, transactions
// ******************************************************************************
string id_generator(string max_id, string header, int body_length)
{
    long int int_id;

    if (max_id != "-1") // there are previous IDs in database
    {
        // cout << max_id.substr(header.size(), body_length) << endl;
        int_id = stoi(max_id.substr(header.size(), body_length)) + 1;
        // new ID is old maximum ID + 1. For example, if the max ID is P00007, the newly generated ID should be P00008
    }
    else            // no previous ID in database
        int_id = 0; // assume the first ID is 0

    if (int_id >= pow(10, body_length) - 1) // depends on the body_length, the available ID can actually run out.
    {
        cout << "Run out of possible ID.\n";
        return "-1"; // Fail to generate ID
    }
    else
        ;

    string s_id = to_string(int_id);                     // convert the digit part of the ID to string
    int init_id_size = s_id.size();                      // original size
    for (int i = 0; i < body_length - init_id_size; i++) // padding the string with heading zeros
    {
        s_id = "0" + s_id;
    }
    s_id = header + s_id; // add the header
    return s_id;
}

// ******************************************************************************
// Function Name:   read_cust_to_vect()
// Parameter:       customer file name, customer vector
// Return:          N/A
// Description:     Function used to load the data from the customer txt file to the vector
// ******************************************************************************
void read_cust_to_vect(string file_name, vector<Customer> &vect)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file) // file does not exist
    {
        cout << "Creating Customer save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (!getline(file, line)) // File is empty
    {
        cout << "empty" << endl;
    }
    else // Start parsing to vect
    {
        do
        {
            // cout << line << endl;
            string id = parse_line(line);
            getline(file, line);

            string username = parse_line(line);
            getline(file, line);

            string first_name = parse_line(line);
            getline(file, line);

            string last_name = parse_line(line);
            getline(file, line);

            string dob = parse_line(line);
            getline(file, line);

            string cred_num = parse_line(line);
            getline(file, line);

            float total_points = stof(parse_line(line));
            getline(file, line);

            // Create Customer object
            Customer cust(id,
                          username,
                          first_name,
                          last_name,
                          dob,
                          cred_num,
                          total_points);
            vect.push_back(cust); // insert object to vector
            // cout << index << endl;
        } while (getline(file, line));
    }
}

// ******************************************************************************
// Function Name:   write_to_cust()
// Parameter:       customer file name, customer vector
// Return:          N/A
// Description:     Function used to save the data to customer txt file
// ******************************************************************************
void write_to_cust(string file_name, vector<Customer> vect)
{
    ofstream file;
    file.open(file_name);

    for (int i = 0; i < vect.size(); i++)
    {
        file << "customer " << i + 1 << " " << vect[i].get_id() << endl;
        file << "customer " << i + 1 << " " << vect[i].get_username() << endl;
        file << "customer " << i + 1 << " " << vect[i].get_fname() << endl;
        file << "customer " << i + 1 << " " << vect[i].get_lname() << endl;
        file << "customer " << i + 1 << " " << vect[i].get_dob() << endl;
        file << "customer " << i + 1 << " " << vect[i].get_cred_num() << endl;
        file << fixed << "customer " << i + 1 << " " << vect[i].get_point() << endl;
        if (i != vect.size() - 1)
        {
            file << endl;
        }
    }

    file.close();
}

// ******************************************************************************
// Function Name:   read_prod_to_vect()
// Parameter:       product file name, product vector
// Return:          N/A
// Description:     Function used to load the data from the product txt file to the vector
// ******************************************************************************
void read_prod_to_vect(string file_name, vector<Product> &vect)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file)
    {
        cout << "Creating Product save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (!getline(file, line)) // File is empty
    {
        cout << "empty" << endl;
    }
    else // Start parsing to vect
    {
        do
        {
            // cout << line << endl;
            string id = parse_line(line);
            getline(file, line);

            string name = parse_line(line);
            getline(file, line);

            float price = stof(parse_line(line));
            getline(file, line);

            int count = stoi(parse_line(line));
            getline(file, line);

            Product prod(id,
                         name,
                         price,
                         count);
            vect.push_back(prod);
            // cout << index << endl;
        } while (getline(file, line));
    }
}

// ******************************************************************************
// Function Name:   write_to_prod()
// Parameter:       product file name, product vector
// Return:          N/A
// Description:     Function used to save the data to product txt file
// ******************************************************************************
void write_to_prod(string file_name, vector<Product> vect)
{
    ofstream file;
    file.open(file_name);

    for (int i = 0; i < vect.size(); i++)
    {
        file << "product " << i + 1 << " " << vect[i].get_id() << endl;
        file << "product " << i + 1 << " " << vect[i].get_name() << endl;
        file << fixed << "product " << i + 1 << " " << vect[i].get_price() << endl;
        file << "product " << i + 1 << " " << vect[i].get_count() << endl;

        if (i != vect.size() - 1)
        {
            file << endl;
        }
    }

    file.close();
}

// ******************************************************************************
// Function Name:   find_cust_by_id()
// Parameter:       customer vector, action - can be "show", "delete" or "check"
// Return:          -1 if user type "exit", 1 if action is "show" or "delete"
//                  and the customer can be found, the customer's index if
//                  action is "check" and the customer can be found
// Description:     Function used to find a customer using ID and either show, delete or check their index
// ******************************************************************************
int find_cust_by_id(vector<Customer> &vect, string action)
{
    string input;
    while (1)
    {
        cout << "Enter Customer ID or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit") // User WANT to exit
                return -1;
            else
                ;

            bool found = false;   // if the customer is found
            int found_index = -1; // the index of wanted customer

            for (int i = 0; i < vect.size(); i++) // Find customer in vector
            {
                if (vect[i].get_id() == input)
                {
                    found_index = i;
                    found = true;
                    break;
                }
            }

            if (!found) // the customer cannot be found
            {
                cout << "Customer not Found.\n";
                continue; // ask again
            }
            else
                ;

            // Acts based on action
            if (action == "show") // display customer's informations
            {
                vect[found_index].show_cust();
                return 1; // Successful
            }
            else if (action == "delete") // delete customer's information
            {
                cout << "Customer profile with ID " << vect[found_index].get_id() << " is deleted.\n";
                vect.erase(vect.begin() + found_index);
                return 1; // Successful
            }
            else if (action == "check") // find the customer's index in vector
            {
                return found_index; // Successful
            }
            else
                ;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
}

// ******************************************************************************
// Function Name:   find_prod_by_id()
// Parameter:       product vector, action - can be "show", "delete" or "check"
// Return:          -2 if user type "exit", -1 id the product cannot be found,
//                  1 if action is "show" or "delete" and the product can be found,
//                  the product's index if action is "check" and the product can be found
// Description:     Function used to find a product using ID and either show, delete or check its index
// ******************************************************************************
int find_prod_by_id(vector<Product> &vect, string action)
{
    string input;
    while (1)
    {
        cout << "Enter Product ID or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit") // User WANT to exit
                return -2;
            else
                ;

            bool found = false;   // if the product is found
            int found_index = -1; // the index of wanted product

            for (int i = 0; i < vect.size(); i++) // Find product in vector
            {
                if (vect[i].get_id() == input)
                {
                    found_index = i;
                    found = true;
                    break;
                }
            }

            if (!found) // the product cannot be found
            {
                cout << "Product not Found\n";
                return -1; // Failure
            }
            else
                ;

            // Acts based on action
            if (action == "show") // display product's informations
            {
                vect[found_index].show_prod();
                return 1; // Successful
            }
            else if (action == "delete") // delete prodcut's information
            {
                cout << "Product profile with ID " << vect[found_index].get_id() << " is deleted.\n";
                vect.erase(vect.begin() + found_index);
                return 1; // Successful
            }
            else if (action == "check") // find the product's index in vector
            {
                return found_index; // Successful
            }
            else
                ;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
}

// ******************************************************************************
// Function Name:   cust_registration()
// Parameter:       customer vector
// Return:          N/A
// Description:     Function used to add new customer
// ******************************************************************************
void cust_registration(vector<Customer> &vect)
{
    bool valid; // to check the state of various functions used below

    // username
    string username;
    valid = input_username(username, vect);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // firstname
    string firstname;
    valid = input_name(firstname, "first");
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // lastname
    string lastname;
    valid = input_name(lastname, "last");
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // dob
    string dob;
    valid = input_dob(dob);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // credit card num
    string cred_num;
    valid = input_cred_num(cred_num, vect);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // ID
    string s_id;
    if (vect.size() >= 1) // Previous ID exist
    {
        s_id = id_generator(vect[vect.size() - 1].get_id(), "CID", 10);
    }
    else // No previous ID exist
    {
        s_id = id_generator("-1", "CID", 10);
    }
    if (s_id == "-1") // Failure
    {
        return;
    }
    else
        ;

    // reward point
    float point;
    valid = input_reward_point(point);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // cout << "username: " << username << "\tfirst name: " << firstname << "\tlast name: " << lastname << "\tdob: " << dob << "\tcred_num: " << cred_num << "\tid: " << s_id << "\tpoint: " << point << endl;
    Customer cust(s_id, username, firstname, lastname, dob, cred_num, point); // Customer object
    vect.push_back(cust);                                                     // insert to vector
}

// ******************************************************************************
// Function Name:   prod_registration()
// Parameter:       product vector
// Return:          N/A
// Description:     Function used to add new product
// ******************************************************************************
void prod_registration(vector<Product> &vect)
{
    bool valid; // to check the state of various functions used below

    // ID
    string s_id;
    if (vect.size() >= 1) // Previous ID exist
    {
        s_id = id_generator(vect[vect.size() - 1].get_id(), "P", 5);
    }
    else // No previous ID exist
    {
        s_id = id_generator("-1", "P", 5);
    }
    if (s_id == "-1") // Failure
    {
        return;
    }
    else
        ;

    // Name
    string description;
    valid = input_prod_description(description);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // Price
    float price;
    valid = input_prod_price(price);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    // Amount in stock
    int in_stock;
    valid = input_prod_stock(in_stock);
    if (!valid) // Failure
    {
        return;
    }
    else // Success
        ;

    Product prod(s_id, description, price, in_stock); // Product object
    vect.push_back(prod);                             // insert to vector
}

// int input_prod_stock(int &in_stock)
// {
//     int input;
//     while (1)
//     {
//         cout << "Enter the number of items in stock or -1 to exit: ";
//         if (cin >> input)
//         {
//             if (input == -1)
//                 return 0;
//             else
//                 ;
//             if (input <= 0)
//             {
//                 cout << "Invalid Input. Number of item must be a positive number.\n";
//                 continue;
//             }
//             in_stock = input;
//             return 1;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// int input_prod_price(float &price)
// {
//     float input;
//     while (1)
//     {
//         cout << "Enter the product price or -1 to exit: ";
//         if (cin >> input)
//         {
//             if (input == -1)
//                 return 0;
//             else
//                 ;
//             if (input <= 0)
//             {
//                 cout << "Invalid Input. Product price must be a positive number.\n";
//                 continue;
//             }
//             price = input;
//             return 1;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// int input_prod_description(string &description)
// {
//     string input;
//     while (1)
//     {
//         cout << "Enter the product description or exit: ";
//         if (getline(cin, input))
//         {
//             if (input == "exit")
//                 return 0;
//             else
//                 ;
//             description = input;
//             return 1;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             cin.ignore(10000, '\n');
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// int input_username(string &username, vector<Customer> vect)
// {
//     string input;
//     while (1)
//     {
//         cout << "Enter a username or exit: ";
//         if (cin >> input)
//         {
//             if (input == "exit")
//                 return 0;
//             else
//                 ;
//             if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789") != string::npos)
//             {
//                 cout << "Invalid Input. The username can only contain characters and numbers.\n";
//                 continue;
//             }
//             else
//                 ;
//             int first_num_index = input.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
//             string username_char = input.substr(0, first_num_index);
//             string username_num;
//             if (first_num_index != string::npos)
//                 username_num = input.substr(first_num_index);
//             else
//             {
//                 username_num = "";
//             }
//             if ((username_char.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos) || (username_char.size() < 8))
//             {
//                 cout << "Invalid Input. The username must start with at least 8 characters.\n";
//                 continue;
//             }
//             else
//                 ;
//             if ((username_num.find_first_not_of("0123456789") != string::npos) || (username_num.size() > 3))
//             {
//                 cout << "Invalid Input. The username must end with at most 3 numbers.\n";
//                 continue;
//             }
//             else
//                 ;
//             bool found = false;
//             for (int i = 0; i < vect.size(); i++)
//             {
//                 if (vect[i].get_username() == input)
//                 {
//                     found = true;
//                     break;
//                 }
//                 else
//                     ;
//             }
//             if (found)
//             {
//                 cout << "Duplicate username.\n";
//                 continue;
//             }
//             else
//             {
//                 username = input;
//                 return 1;
//             }
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//         }
//     }
// }

// int input_name(string &name, string type)
// {
//     string input;
//     while (1)
//     {
//         cout << "Enter your " << type << " name or exit: ";
//         if (cin >> input)
//         {
//             if (input == "exit")
//                 return 0;
//             else
//                 ;
//             if (input.size() > 15)
//             {
//                 cout << "Invalid input. Your " << type << " name cannot contain more than 15 characters.\n";
//                 continue;
//             }
//             else
//                 ;
//             if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos)
//             {
//                 cout << "Invalid input. Your " << type << " name can only contain characters in the alphabet.\n";
//                 continue;
//             }
//             else
//                 ;
//             name = input;
//             return 1;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//         }
//     }
// }

// int input_dob(string &dob)
// {
//     // year
//     int year;
//     while (1)
//     {
//         cout << "Enter your year of birth or -1 to exit: ";
//         if (cin >> year)
//         {
//             if (year == -1)
//                 return 0;
//             else
//                 ;
//             if ((year < 0) || (year > 9999))
//             {
//                 cout << "Your year of birth must be between 0 and 9999.\n";
//                 continue;
//             }
//             else
//                 ;
//             break;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
//     // month
//     int month;
//     while (1)
//     {
//         cout << "Enter your month of birth or -1 to exit: ";
//         if (cin >> month)
//         {
//             if (month == -1)
//                 return 0;
//             else
//                 ;
//             if ((month < 0) || (month > 12))
//             {
//                 cout << "Your month of birth must be between 1 and 12.\n";
//                 continue;
//             }
//             else
//                 ;
//             break;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
//     // day
//     int day;
//     vector<int> thirty_one = {1, 3, 5, 7, 8, 10, 12};
//     vector<int> thirty = {4, 6, 9, 11};
//     int day_max = 0;
//     while (1)
//     {
//         cout << "Enter your day of birth or -1 to exit: ";
//         if (cin >> day)
//         {
//             if (day == -1)
//                 return 0;
//             else
//                 ;
//             if (day < 0)
//             {
//                 cout << "Your day of birth cannot be smaller than 0.\n";
//                 continue;
//             }
//             else
//                 ;
//             for (auto &m : thirty)
//             {
//                 if (month == m)
//                 {
//                     day_max = 30;
//                 }
//                 else
//                     ;
//             }
//             for (auto &m : thirty_one)
//             {
//                 if (month == m)
//                 {
//                     day_max = 31;
//                 }
//                 else
//                     ;
//             }
//             if ((month == 2) && (year % 4 != 0))
//             {
//                 day_max = 28;
//             }
//             else if ((month == 2) && (year % 4 == 0) && (year % 100 != 0))
//             {
//                 day_max = 29;
//             }
//             else if ((month == 2) && (year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0))
//             {
//                 day_max = 28;
//             }
//             else if ((month == 2) && (year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
//             {
//                 day_max = 29;
//             }
//             else
//                 ;
//             if (day > day_max)
//             {
//                 cout << "Invalid input. Your day of birth cannot be bigger than " << day_max << ".\n";
//                 continue;
//             }
//             else
//                 ;
//             break;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
//     string s_year, s_month, s_day;
//     if (year < 10)
//     {
//         s_year = "000" + to_string(year);
//     }
//     else if ((year >= 10) && (year < 100))
//     {
//         s_year = "00" + to_string(year);
//     }
//     else if ((year >= 100) && (year < 1000))
//     {
//         s_year = "0" + to_string(year);
//     }
//     else if (year >= 1000)
//     {
//         s_year = to_string(year);
//     }
//     else
//         ;
//     if (month < 10)
//     {
//         s_month = "0" + to_string(month);
//     }
//     else
//     {
//         s_month = to_string(month);
//     }
//     if (day < 10)
//     {
//         s_day = "0" + to_string(day);
//     }
//     else
//     {
//         s_day = to_string(day);
//     }
//     dob = s_month + "-" + s_day + "-" + s_year;
//     return 1;
// }

// int input_cred_num(string &cred_num, vector<Customer> vect)
// {
//     string input;
//     while (1)
//     {
//         cout << "Enter your credit card number without the dash (-) or exit: ";
//         if (cin >> input)
//         {
//             if (input == "exit")
//                 return 0;
//             else
//                 ;
//             if (input.find_first_not_of("0123456789") != string::npos)
//             {
//                 cout << "Invalid Input. The credit card number must contain 12 numbers.\n";
//                 continue;
//             }
//             else
//                 ;
//             if (input.size() != 12)
//             {
//                 cout << "Invalid Input. The credit card number must contain 12 numbers.\n";
//                 continue;
//             }
//             else
//                 ;
//             input = input.substr(0, 4) + "-" + input.substr(4, 4) + "-" + input.substr(8, 4);
//             bool found = false;
//             for (int i = 0; i < vect.size(); i++)
//             {
//                 if (vect[i].get_cred_num() == input)
//                 {
//                     found = true;
//                     break;
//                 }
//                 else
//                     ;
//             }
//             if (found)
//             {
//                 cout << "Duplicate credit card number.\n";
//                 continue;
//             }
//             else
//             {
//                 cred_num = input;
//                 return 1;
//             }
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// int input_reward_point(float &point)
// {
//     float input;
//     while (1)
//     {
//         cout << "Enter your initial point or -1 to exit: ";
//         if (cin >> input)
//         {
//             if (input == -1)
//                 return 0;
//             else
//                 ;
//             if (input <= 0)
//             {
//                 cout << "Invalid Input. Your point must be a positive number.\n";
//                 continue;
//             }
//             else
//                 ;
//             point = input;
//             return 1;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// float input_ratio(string type)
// {
//     float input, ratio;
//     while (1)
//     {
//         if (type == "reward")
//             cout << "Enter the new reward ratio from 1 USD to x point(s) or -1 to exit: ";
//         else if (type == "redeem")
//             cout << "Enter the new redeem ratio from 1 point to x USD(s) or -1 to exit: ";
//         else
//             ;
//         if (cin >> input)
//         {
//             if (input == -1)
//                 return -1;
//             else
//                 ;
//             if (input <= 0)
//             {
//                 cout << "Invalid Input. Ratio must be a positive number.\n";
//                 continue;
//             }
//             else
//                 ;
//             ratio = input;
//             return ratio;
//         }
//         else
//         {
//             cout << "Invalid Input" << endl;
//             cin.clear();
//             while (cin.get() != '\n')
//                 ; // empty loop
//         }
//     }
// }

// ******************************************************************************
// Function Name:   change_reward_ratio()
// Parameter:       general file name, reward and redeem ratio, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to change the ratio from USD to points when customer shop
// ******************************************************************************
void change_reward_ratio(string gen_file, float &reward_ratio, float redeem_ratio, int max_rtid)
{
    cout << "Current reward ratio is " << reward_ratio << endl; // Display current ratio
    float temp;                                                 // temporary variable
    temp = input_ratio("reward");                               // get input from the user
    if (temp != -1)                                             // Valid input
    {
        reward_ratio = temp;                                          // Change reward ratio
        save_general(gen_file, reward_ratio, redeem_ratio, max_rtid); // Save to file
    }
    else // Invalid input
        ;
}

// ******************************************************************************
// Function Name:   change_redeem_ratio()
// Parameter:       general file name, reward and redeem ratio, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to change the ratio from points to USD when customer redeem
// ******************************************************************************
void change_redeem_ratio(string gen_file, float reward_ratio, float &redeem_ratio, int max_rtid)
{
    cout << "Current redeem ratio is " << redeem_ratio << endl; // Display current ratio
    float temp;                                                 // temporary variable
    temp = input_ratio("redeem");                               // get input from the user
    if (temp != -1)                                             // Valid input
    {
        redeem_ratio = temp;                                          // Change redeem ratio
        save_general(gen_file, reward_ratio, redeem_ratio, max_rtid); // Save to file
    }
    else
        ;
}

// ******************************************************************************
// Function Name:   save_general()
// Parameter:       general file name, reward and redeem ratio, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to save the data to the general txt file
// ******************************************************************************
void save_general(string file_name, float reward_ratio, float redeem_ratio, int max_rtid)
{
    ofstream file;
    file.open(file_name);

    file << "Reward Ratio " << reward_ratio << endl;
    file << "Redeem Ratio " << redeem_ratio << endl;
    file << "Max RTID " << max_rtid << endl;

    file.close();
}

// ******************************************************************************
// Function Name:   save_shopping_config()
// Parameter:       config file name, current max shopping transaction ID (max_tid)
// Return:          N/A
// Description:     Function used to save the data to the config txt file
// ******************************************************************************
void save_shopping_config(string config_file, int max_tid)
{
    ofstream file;

    file.open(config_file);
    file << "Max STID " << max_tid << endl;

    file.close();
}

// ******************************************************************************
// Function Name:   get_general()
// Parameter:       general file name, reward and redeem ratio, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to load data from the general txt file
// ******************************************************************************
void get_general(string file_name, float &reward_ratio, float &redeem_ratio, int &max_rtid)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file) // File does not exist
    {
        cout << "Creating general save file...\n";
        // Create run_log
        ofstream new_file;
        // Create new file
        new_file.open(file_name);
        // Set the default values
        cout << "Saving the reward ratio as 1...\n";
        new_file << "Reward Ratio 1" << endl;
        cout << "Saving the redeem ratio as 0.1...\n";
        new_file << "Reward Ratio 0.1" << endl;
        cout << "Saving the max Redeem Transaction ID as 0...\n";
        new_file << "Max RTID 0" << endl;
        new_file.close();
        reward_ratio = 1;
        redeem_ratio = 0.1;
        max_rtid = 0;
        return;
    }
    else
        ;

    getline(file, line);
    reward_ratio = stof(parse_line(line));
    getline(file, line);
    redeem_ratio = stof(parse_line(line));
    getline(file, line);
    max_rtid = stof(parse_line(line));
}

// ******************************************************************************
// Function Name:   get_shopping_config()
// Parameter:       config name, current max shopping transaction ID (max_stid)
// Return:          N/A
// Description:     Function used to load data from the config txt file
// ******************************************************************************
void get_shopping_config(int &max_stid, string file_name)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file) // File does not exist
    {
        cout << "Creating shopping save file...\n";
        // Create run_log
        ofstream new_file;
        // Create new file
        new_file.open(file_name);
        // Set the default values
        cout << "Saving the max shopping Transaction ID as 0...\n";
        new_file << "Max RTID 0" << endl;
        new_file.close();
        max_stid = 0;
        return;
    }
    else
        ;

    getline(file, line);
    max_stid = stof(parse_line(line));
}

// ******************************************************************************
// Function Name:   redeem_prod()
// Parameter:       product vector, customer vector, redeem ratio,
//                  general and redeem transaction file name, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to allow the user to redeem reward and keep track of it
// ******************************************************************************
void redeem_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid)
{
    string input;
    int cust_index; // customer index in the vector

    cout << "Please log in to redeem or exit: \n";
    cust_index = find_cust_by_id(cust_vect, "check"); // get the customer's index if they are in the vector
    if (cust_index == -1)                             // Not found customer or user typed "exit"
    {
        return;
    }
    else
        ;

    cout << "Hello, " << cust_vect[cust_index].get_fname() << " " << cust_vect[cust_index].get_lname() << ".\n";
    cout << fixed << "Your current number of reward points is " << cust_vect[cust_index].get_point() << ".\n";

    int prod_index, // product index in vector
        state;      // output state for redeem_transaction

    while (1)
    {
        // Redeem transaction
        state = redeem_transaction(prod_vect, cust_vect, prod_index, cust_index, redeem_ratio, gen_file, r_transact_file, max_rtid);
        if (state == -2) // user WANT to exit
        {
            return;
        }
        else if (state == -1) // invalid product or successful transaction. Either way, initiate a new transaction
        {
            continue;
        }
        else
            ;
    }
}

// ******************************************************************************
// Function Name:   redeem_transaction()
// Parameter:       product vector, customer vector, redeem ratio, product and customer index
//                  general and redeem transaction file name, current max redeem transaction ID (max_rtid)
// Return:          N/A
// Description:     Function used to allow the user to perform ONE transaction to redeem ONE product
// ******************************************************************************
int redeem_transaction(vector<Product> &prod_vect, vector<Customer> &cust_vect, int &prod_index, int &cust_index, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid)
{
    // Display products
    cout << "Available Products: \n\n";
    display_redeem_product(prod_vect, redeem_ratio);

    // Display current reward points
    cout << "Your current number of reward points is " << cust_vect[cust_index].get_point() << ".\n";

    // Ask user for a product using product ID
    prod_index = find_prod_by_id(prod_vect, "check");

    if (prod_index == -2) // user WANT to exit
    {
        return -2;
    }
    else if (prod_index == -1) // product cannot be found
    {
        return -1;
    }
    else
        ;

    // Out of stock
    if (prod_vect[prod_index].get_count() == 0)
    {
        cout << "No item left in stock. Please try another product.\n";
        return -1;
    }
    // Product's value in points is bigger than the customer's remaining points
    else if (prod_vect[prod_index].get_price() / redeem_ratio > cust_vect[cust_index].get_point())
    {
        cout << "You do not have enough points to redeem this product.\n";
        return -1;
    }
    else
        ;

    // Update item count in stock
    prod_vect[prod_index].set_count(prod_vect[prod_index].get_count() - 1);
    // Update customer's reward point
    cust_vect[cust_index].set_point(cust_vect[cust_index].get_point() - prod_vect[prod_index].get_price() / redeem_ratio);
    // Confirm transaction
    cout << "You have redeem 1 " << prod_vect[prod_index].get_name() << ". Your new number of reward point is " << cust_vect[cust_index].get_point() << ".\n";
    // Save to log file
    append_to_r_transact(r_transact_file, max_rtid, cust_vect[cust_index].get_id(), prod_vect[prod_index].get_id(), prod_vect[prod_index].get_price(), prod_vect[prod_index].get_price() / redeem_ratio);
    max_rtid++; // Increment max redeem transaction ID

    // Save new max redeem transaction ID
    float rw_ratio, rd_ratio;
    get_general(gen_file, rw_ratio, rd_ratio, max_rtid);
    save_general(gen_file, rw_ratio, rd_ratio, max_rtid);

    return -1; // Successful transaction
}

// ******************************************************************************
// Function Name:   display_redeem_product()
// Parameter:       product vector, redeem ratio
// Return:          N/A
// Description:     Function used to display the product and their price in points for redeem
// ******************************************************************************
void display_redeem_product(vector<Product> &prod_vect, float redeem_ratio)
{
    for (int i = 0; i < prod_vect.size(); i++)
    {
        cout << "Product ID: " << prod_vect[i].get_id() << endl;
        cout << "Product Description: " << prod_vect[i].get_name() << endl;
        cout << "Product Price: " << prod_vect[i].get_price() / redeem_ratio << " point(s)" << endl;
        cout << prod_vect[i].get_count() << " item(s) are left in stock.\n\n";
    }
}

// ******************************************************************************
// Function Name:   display_shop_product()
// Parameter:       product vector
// Return:          N/A
// Description:     Function used to display the product and their price in USD for shopping
// ******************************************************************************
void display_shop_product(vector<Product> &prod_vect)
{
    for (int i = 0; i < prod_vect.size(); i++)
    {
        cout << "Product ID: " << prod_vect[i].get_id() << endl;
        cout << "Product Description: " << prod_vect[i].get_name() << endl;
        cout << "Product Price: " << prod_vect[i].get_price() << endl;
        cout << prod_vect[i].get_count() << " item(s) are left in stock.\n\n";
    }
}

// ******************************************************************************
// Function Name:   append_to_r_transact()
// Parameter:       redeem transaction file name, max redeem transaction ID,
//                  customer ID, product ID, product price in USD and point
// Return:          N/A
// Description:     Function used to save the record of a redeem transaction to a redeem transaction log file
// ******************************************************************************
void append_to_r_transact(string file_name, int &max_tid, string cust_id, string prod_id, float prod_price, float prod_point)
{
    ofstream file;

    file.open(file_name, ios_base::app); // Append to file

    if (!file) // File does not exist
    {
        cout << "Creating Redeem Transaction save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (max_tid == 0) // no previous ID exist
    {
        file << "Transaction ID " << id_generator("T0000000000", "T", 10) << endl;
    }
    else // previous ID exist
    {
        string s_id = to_string(max_tid);
        int init_id_size = s_id.size();
        for (int i = 0; i < 10 - init_id_size; i++)
        {
            s_id = "0" + s_id;
        }
        s_id = "T" + s_id;
        file << "Transaction ID " << id_generator(s_id, "T", 10) << endl;
    }
    file << "Customer ID " << cust_id << endl;
    file << "Product ID " << prod_id << endl;
    file << "Price: $" << prod_price << endl;
    file << "Points deducted: " << prod_point << endl
         << endl;

    file.close();
}

// ******************************************************************************
// Function Name:   shop_prod()
// Parameter:       product vector, customer vector, reward ratio,
//                  config and shopping transaction file name, current max shopping transaction ID (max_stid)
// Return:          N/A
// Description:     Function used to allow the user to shop multiple products
// ******************************************************************************
void shop_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float reward_ratio, int &max_tid, string config_file, string file_name)
{

    cout << "Please log in to shop or exit\n";

    int cust_index = find_cust_by_id(cust_vect, "check"); // get the customer's index if they are in the vector

    if (cust_index == -1) // Not found customer or user typed "exit"
        return;
    cout << "\nHello, " << cust_vect[cust_index].get_fname() << " " << cust_vect[cust_index].get_lname() << ".\n";

    map<int, int> shop_cart;
    print_cart(shop_cart, prod_vect); // Display current shopping cart

    cout << "Below is the list of available product\n\n";
    display_shop_product(prod_vect); // Display products

    while (1)
    {
        int state = add_to_cart(shop_cart, prod_vect);
        if (state == -2) // User WANT to exit
            break;
        else if (state == -1) // invalid product or successful shopping. Either way, ask again
            continue;

        cout << "\nYour current cart\n";
        print_cart(shop_cart, prod_vect); // Display current shopping cart
    }

    // CHECK OUT
    string input;
    while (1)
    {
        float sub_total = print_cart(shop_cart, prod_vect);              // Display current shopping cart
        cout << "Your total is: " << sub_total << endl;                  // Total price of the cart
        cout << "Points received: " << sub_total * reward_ratio << endl; // Total reward points received if proceed

        cout << "Checkout ?(y/n): ";
        if (cin >> input)
        {
            if (input == "y") // Confirm checkout
            {
                float total = 0; // Total price

                for (auto pair : shop_cart) // For every item in cart
                {
                    // set new cout
                    int new_count = prod_vect[pair.first].get_count() - pair.second;
                    prod_vect[pair.first].set_count(new_count);
                    // Calculate total price
                    total += prod_vect[pair.first].get_price() * pair.second;
                }
                // add reward to cust
                float new_reward = cust_vect[cust_index].get_point() + total * reward_ratio;
                cust_vect[cust_index].set_point(new_reward);
                // save transaction
                append_to_s_transact(config_file,
                                     file_name,
                                     max_tid,
                                     shop_cart,
                                     cust_vect[cust_index],
                                     prod_vect,
                                     reward_ratio);
                break;
            }
            else if (input == "n") // Discard cart
            {
                cout << "Cart deleted\n";
                return;
            }
            else
                continue;
        }
    }
}

// ******************************************************************************
// Function Name:   add_to_cart()
// Parameter:       shop cart, product vector
// Return:          -2 if user want to exit, -1 if user want to choose different product
// Description:     Function used to allow the user to shop multiple items of ONE product
// ******************************************************************************
int add_to_cart(map<int, int> &shop_cart, vector<Product> &prod_vect)
{
    int prod_index;
    while (1)
    {
        cout << "Enter exit to continue to check out\n";
        prod_index = find_prod_by_id(prod_vect, "check"); // Find product by id
        if (prod_index == -2)                             // user WANT to exit
        {
            return -2;
        }
        else if (prod_index == -1) // product not found
        {
            continue;
        }
        else
            break;
    }

    int prod_count;
    int input;
    while (1)
    {
        cout << "Please enter amount, -2 to exit to main menu, or -1 to choose a different product:";
        if (cin >> input)
        {
            if (input == -2) // user WANT to exit
                return -2;
            else if (input == -1) // choose different product
                return -1;
            // Amount is bigger than 0 and smaller than the amount of items left in stock
            if ((input > 0) && (input <= prod_vect[prod_index].get_count()))
            {
                prod_count = input;
                // insert to cart
                auto itr = shop_cart.find(prod_index);
                if (itr != shop_cart.end())
                    itr->second += prod_count;
                else
                    shop_cart.insert({prod_index, prod_count});

                // int new_count = prod_vect[prod_index].get_count() - prod_count;
                // prod_vect[prod_index].set_count(new_count);
                break;
            }
            else
            {
                cout << "Invalid ammount.\n";
                continue;
            }
        }
    }
}

// ******************************************************************************
// Function Name:   print_cart()
// Parameter:       shop cart, product vector
// Return:          the total price of items in cart
// Description:     Function used to display the current shopping cart
// ******************************************************************************
float print_cart(map<int, int> &shop_cart, vector<Product> &prod_vect)
{
    float total = 0; // Total price of items in cart
    cout << endl;
    for (auto pair : shop_cart)
    {
        cout << prod_vect[pair.first].get_name() << ": " << pair.second << " item(s)\n";
        total += prod_vect[pair.first].get_price() * pair.second;
    }
    cout << "Your Sub-Total is: " << total << "\n\n";
    return total;
}

// ******************************************************************************
// Function Name:   append_to_s_transact()
// Parameter:       shopping transaction and config file name, max shopping transaction ID,
//                  shopping cart, the customer, product vector, reward ratio
// Return:          N/A
// Description:     Function used to save the record of a shopping transaction to a shopping transaction log file
// ******************************************************************************
void append_to_s_transact(string config_file, string file_name, int max_tid, map<int, int> &shop_cart, Customer cust, vector<Product> vect, float reward_ratio)
{
    ofstream file;
    file.open(file_name, ios_base::app); // Append to file

    if (!file) // File does not exist
    {
        cout << "Creating Shopping Transaction save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (max_tid == 0) // no previous ID exist
    {
        file << "Transaction ID " << id_generator("S0000000000", "S", 10) << endl;
    }
    else // previous ID exist
    {
        string s_id = to_string(max_tid);
        int init_id_size = s_id.size();
        for (int i = 0; i < 10 - init_id_size; i++)
        {
            s_id = "0" + s_id;
        }
        s_id = "S" + s_id;
        file << "Transaction ID " << id_generator(s_id, "S", 10) << endl;
    }
    file << "Customer ID " << cust.get_id() << endl;

    // Print cart
    float total;
    for (map<int, int>::iterator it = shop_cart.begin(); it != shop_cart.end(); ++it)
    {
        file << vect[it->first].get_id() << " " << it->second;
        total += vect[it->first].get_price() * it->second;

        if (it != shop_cart.end())
            file << ", ";
    }

    file << endl
         << total << endl;
    file << total * reward_ratio << endl;

    max_tid++;
    save_shopping_config(config_file, max_tid);
}