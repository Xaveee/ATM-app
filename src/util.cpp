#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <map>

#include "../include/Customer.h"
#include "../include/Product.h"
#include "../include/util.h"

using namespace std;

string parse_line(string line)
{
    int index;
    index = line.find_last_of(" ") + 1;
    // cout << line.substr(index, line.length() - 1) << endl;
    return line.substr(index, line.length() - 1);
}

void read_cust_to_vect(string file_name, vector<Customer> &vect)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file)
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

            Customer cust(id,
                          username,
                          first_name,
                          last_name,
                          dob,
                          cred_num,
                          total_points);
            vect.push_back(cust);
            // cout << index << endl;
        } while (getline(file, line));
    }
}

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

int find_cust_by_id(vector<Customer> &vect, string action)
{
    string input;
    while (1)
    {
        cout << "Enter Customer id or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit")
                return -1;
            else
                ;
            bool found = false;
            int found_index = -1;
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i].get_id() == input)
                {
                    found_index = i;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Customer not Found\n";
                continue;
            }
            else
                ;
            if (action == "show")
            {
                vect[found_index].show_cust();
                return 1;
            }
            else if (action == "delete")
            {
                cout << "Customer profile with ID " << vect[found_index].get_id() << " is deleted.\n";
                vect.erase(vect.begin() + found_index);
                return 1;
            }
            else if (action == "check")
            {
                return found_index;
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

int find_prod_by_id(vector<Product> &vect, string action)
{
    string input;
    while (1)
    {
        cout << "Enter product id or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit")
                return -2;
            else
                ;
            bool found = false;
            int found_index = -1;
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i].get_id() == input)
                {
                    found_index = i;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Product not Found\n";
                return -1;
            }
            else
                ;
            if (action == "show")
            {
                vect[found_index].show_prod();
                return 1;
            }
            else if (action == "delete")
            {
                cout << "Product profile with ID " << vect[found_index].get_id() << " is deleted.\n";
                vect.erase(vect.begin() + found_index);
                return 1;
            }
            else if (action == "check")
            {
                return found_index;
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

void cust_registration(vector<Customer> &vect)
{
    bool valid;
    // username
    string username;
    valid = input_username(username, vect);
    if (!valid)
    {
        return;
    }
    else
        ;
    // firstname
    string firstname;
    valid = input_name(firstname, "first");
    if (!valid)
    {
        return;
    }
    else
        ;
    // lastname
    string lastname;
    valid = input_name(lastname, "last");
    if (!valid)
    {
        return;
    }
    else
        ;
    // dob
    string dob;
    valid = input_dob(dob);
    if (!valid)
    {
        return;
    }
    else
        ;
    // credit card num
    string cred_num;
    valid = input_cred_num(cred_num, vect);
    if (!valid)
    {
        return;
    }
    else
        ;
    // ID
    string s_id;
    if (vect.size() >= 1)
    {
        s_id = id_generator(vect[vect.size() - 1].get_id(), "CID", 10);
    }
    else
    {
        s_id = id_generator("-1", "CID", 10);
    }
    if (s_id == "-1")
    {
        return;
    }
    else
        ;
    // reward point
    float point;
    valid = input_reward_point(point);
    if (!valid)
    {
        return;
    }
    else
        ;
    // cout << "username: " << username << "\tfirst name: " << firstname << "\tlast name: " << lastname << "\tdob: " << dob << "\tcred_num: " << cred_num << "\tid: " << s_id << "\tpoint: " << point << endl;
    Customer cust(s_id, username, firstname, lastname, dob, cred_num, point);
    vect.push_back(cust);
}

void prod_registration(vector<Product> &vect)
{
    bool valid;
    // ID
    string s_id;
    if (vect.size() >= 1)
    {
        s_id = id_generator(vect[vect.size() - 1].get_id(), "P", 5);
    }
    else
    {
        s_id = id_generator("-1", "P", 5);
    }
    if (s_id == "-1")
    {
        return;
    }
    else
        ;

    // Name
    string description;
    valid = input_prod_description(description);
    if (!valid)
    {
        return;
    }
    else
        ;
    // Price
    float price;
    valid = input_prod_price(price);
    if (!valid)
    {
        return;
    }
    else
        ;
    // Amount in stock
    int in_stock;
    valid = input_prod_stock(in_stock);
    if (!valid)
    {
        return;
    }
    else
        ;

    Product prod(s_id, description, price, in_stock);
    vect.push_back(prod);
}

int input_prod_stock(int &in_stock)
{
    int input;
    while (1)
    {
        cout << "Enter the number of items in stock or -1 to exit: ";
        if (cin >> input)
        {
            if (input == -1)
                return 0;
            else
                ;
            if (input <= 0)
            {
                cout << "Invalid Input. Number of item must be a positive number.\n";
                continue;
            }
            in_stock = input;
            return 1;
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

int input_prod_price(float &price)
{
    float input;
    while (1)
    {
        cout << "Enter the product price or -1 to exit: ";
        if (cin >> input)
        {
            if (input == -1)
                return 0;
            else
                ;
            if (input <= 0)
            {
                cout << "Invalid Input. Product price must be a positive number.\n";
                continue;
            }
            price = input;
            return 1;
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

int input_prod_description(string &description)
{
    string input;
    while (1)
    {
        cout << "Enter the product description or exit: ";
        if (getline(cin, input))
        {
            if (input == "exit")
                return 0;
            else
                ;
            description = input;
            return 1;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
}

string id_generator(string max_id, string header, int body_length)
{
    long int int_id;
    if (max_id != "-1")
    {
        // cout << max_id.substr(header.size(), body_length) << endl;
        int_id = stoi(max_id.substr(header.size(), body_length)) + 1;
    }
    else
        int_id = 0;
    if (int_id >= pow(10, body_length) - 1)
    {
        cout << "Run out of possible ID.\n";
        return "-1";
    }
    else
        ;
    string s_id = to_string(int_id);
    int init_id_size = s_id.size();
    for (int i = 0; i < body_length - init_id_size; i++)
    {
        s_id = "0" + s_id;
    }
    s_id = header + s_id;
    return s_id;
}

int input_username(string &username, vector<Customer> vect)
{
    string input;
    while (1)
    {
        cout << "Enter a username or exit: ";
        if (cin >> input)
        {
            if (input == "exit")
                return 0;
            else
                ;
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789") != string::npos)
            {
                cout << "Invalid Input. The username can only contain characters and numbers.\n";
                continue;
            }
            else
                ;
            int first_num_index = input.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
            string username_char = input.substr(0, first_num_index);
            string username_num;
            if (first_num_index != string::npos)
                username_num = input.substr(first_num_index);
            else
            {
                username_num = "";
            }
            if ((username_char.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos) || (username_char.size() < 8))
            {
                cout << "Invalid Input. The username must start with at least 8 characters.\n";
                continue;
            }
            else
                ;
            if ((username_num.find_first_not_of("0123456789") != string::npos) || (username_num.size() > 3))
            {
                cout << "Invalid Input. The username must end with at most 3 numbers.\n";
                continue;
            }
            else
                ;
            bool found = false;
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i].get_username() == input)
                {
                    found = true;
                    break;
                }
                else
                    ;
            }
            if (found)
            {
                cout << "Duplicate username.\n";
                continue;
            }
            else
            {
                username = input;
                return 1;
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }
}

int input_name(string &name, string type)
{
    string input;
    while (1)
    {
        cout << "Enter your " << type << " name or exit: ";
        if (cin >> input)
        {
            if (input == "exit")
                return 0;
            else
                ;
            if (input.size() > 15)
            {
                cout << "Invalid input. Your " << type << " name cannot contain more than 15 characters.\n";
                continue;
            }
            else
                ;
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos)
            {
                cout << "Invalid input. Your " << type << " name can only contain characters in the alphabet.\n";
                continue;
            }
            else
                ;
            name = input;
            return 1;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }
}

int input_dob(string &dob)
{
    // year
    int year;
    while (1)
    {
        cout << "Enter your year of birth or -1 to exit: ";
        if (cin >> year)
        {
            if (year == -1)
                return 0;
            else
                ;
            if ((year < 0) || (year > 9999))
            {
                cout << "Your year of birth must be between 0 and 9999.\n";
                continue;
            }
            else
                ;
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
    // month
    int month;
    while (1)
    {
        cout << "Enter your month of birth or -1 to exit: ";
        if (cin >> month)
        {
            if (month == -1)
                return 0;
            else
                ;
            if ((month < 0) || (month > 12))
            {
                cout << "Your month of birth must be between 1 and 12.\n";
                continue;
            }
            else
                ;
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
    // day
    int day;
    vector<int> thirty_one = {1, 3, 5, 7, 8, 10, 12};
    vector<int> thirty = {4, 6, 9, 11};
    int day_max = 0;
    while (1)
    {
        cout << "Enter your day of birth or -1 to exit: ";
        if (cin >> day)
        {
            if (day == -1)
                return 0;
            else
                ;
            if (day < 0)
            {
                cout << "Your day of birth cannot be smaller than 0.\n";
                continue;
            }
            else
                ;
            for (auto &m : thirty)
            {
                if (month == m)
                {
                    day_max = 30;
                }
                else
                    ;
            }
            for (auto &m : thirty_one)
            {
                if (month == m)
                {
                    day_max = 31;
                }
                else
                    ;
            }
            if ((month == 2) && (year % 4 != 0))
            {
                day_max = 28;
            }
            else if ((month == 2) && (year % 4 == 0) && (year % 100 != 0))
            {
                day_max = 29;
            }
            else if ((month == 2) && (year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0))
            {
                day_max = 28;
            }
            else if ((month == 2) && (year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
            {
                day_max = 29;
            }
            else
                ;
            if (day > day_max)
            {
                cout << "Invalid input. Your day of birth cannot be bigger than " << day_max << ".\n";
                continue;
            }
            else
                ;
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            while (cin.get() != '\n')
                ; // empty loop
        }
    }
    string s_year, s_month, s_day;
    if (year < 10)
    {
        s_year = "000" + to_string(year);
    }
    else if ((year >= 10) && (year < 100))
    {
        s_year = "00" + to_string(year);
    }
    else if ((year >= 100) && (year < 1000))
    {
        s_year = "0" + to_string(year);
    }
    else if (year >= 1000)
    {
        s_year = to_string(year);
    }
    else
        ;
    if (month < 10)
    {
        s_month = "0" + to_string(month);
    }
    else
    {
        s_month = to_string(month);
    }
    if (day < 10)
    {
        s_day = "0" + to_string(day);
    }
    else
    {
        s_day = to_string(day);
    }
    dob = s_month + "-" + s_day + "-" + s_year;
    return 1;
}

int input_cred_num(string &cred_num, vector<Customer> vect)
{
    string input;
    while (1)
    {
        cout << "Enter your credit card number without the dash (-) or exit: ";
        if (cin >> input)
        {
            if (input == "exit")
                return 0;
            else
                ;
            if (input.find_first_not_of("0123456789") != string::npos)
            {
                cout << "Invalid Input. The credit card number must contain 12 numbers.\n";
                continue;
            }
            else
                ;
            if (input.size() != 12)
            {
                cout << "Invalid Input. The credit card number must contain 12 numbers.\n";
                continue;
            }
            else
                ;
            input = input.substr(0, 4) + "-" + input.substr(4, 4) + "-" + input.substr(8, 4);
            bool found = false;
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i].get_cred_num() == input)
                {
                    found = true;
                    break;
                }
                else
                    ;
            }
            if (found)
            {
                cout << "Duplicate credit card number.\n";
                continue;
            }
            else
            {
                cred_num = input;
                return 1;
            }
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

int input_reward_point(float &point)
{
    float input;
    while (1)
    {
        cout << "Enter your initial point or -1 to exit: ";
        if (cin >> input)
        {
            if (input == -1)
                return 0;
            else
                ;
            if (input <= 0)
            {
                cout << "Invalid Input. Your point must be a positive number.\n";
                continue;
            }
            else
                ;
            point = input;
            return 1;
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

float input_ratio(string type)
{
    float input, ratio;
    while (1)
    {
        if (type == "reward")
            cout << "Enter the new reward ratio from 1 USD to x point(s) or -1 to exit: ";
        else if (type == "redeem")
            cout << "Enter the new redeem ratio from 1 point to x USD(s) or -1 to exit: ";
        else
            ;
        if (cin >> input)
        {
            if (input == -1)
                return -1;
            else
                ;
            if (input <= 0)
            {
                cout << "Invalid Input. Ratio must be a positive number.\n";
                continue;
            }
            else
                ;
            ratio = input;
            return ratio;
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

void change_reward_ratio(string gen_file, float &reward_ratio, float redeem_ratio, int max_rtid)
{
    cout << "Current reward ratio is " << reward_ratio << endl;
    float temp;
    temp = input_ratio("reward");
    if (temp != -1)
    {
        reward_ratio = temp;
        save_general(gen_file, reward_ratio, redeem_ratio, max_rtid);
    }
    else
        ;
}

void change_redeem_ratio(string gen_file, float reward_ratio, float &redeem_ratio, int max_rtid)
{
    cout << "Current redeem ratio is " << redeem_ratio << endl;
    float temp;
    temp = input_ratio("redeem");
    if (temp != -1)
    {
        redeem_ratio = temp;
        save_general(gen_file, reward_ratio, redeem_ratio, max_rtid);
    }
    else
        ;
}

void save_general(string file_name, float reward_ratio, float redeem_ratio, int max_rtid)
{
    ofstream file;
    file.open(file_name);

    file << "Reward Ratio " << reward_ratio << endl;
    file << "Redeem Ratio " << redeem_ratio << endl;
    file << "Max RTID " << max_rtid << endl;

    file.close();
}
void save_shopping_config(string config_file, int max_tid)
{
    ofstream file;

    file.open(config_file);
    file << "Max STID " << max_tid << endl;

    file.close();
}

void get_general(string file_name, float &reward_ratio, float &redeem_ratio, int &max_rtid)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file)
    {
        cout << "Creating general save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
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

void get_shopping_config(int &max_stid, string file_name)
{
    string line;

    ifstream file;
    file.open(file_name);

    if (!file)
    {
        cout << "Creating shopping save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
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
void redeem_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid)
{
    string input;
    int cust_index;
    cust_index = find_cust_by_id(cust_vect, "check");
    if (cust_index == -1)
    {
        return;
    }
    else
        ;
    cout << "Hello, " << cust_vect[cust_index].get_fname() << " " << cust_vect[cust_index].get_lname() << ".\n";
    cout << fixed << "Your current number of reward points is " << cust_vect[cust_index].get_point() << ".\n";

    string pid;
    int prod_index, state;

    while (1)
    {
        state = redeem_transaction(prod_vect, cust_vect, prod_index, cust_index, redeem_ratio, gen_file, r_transact_file, max_rtid);
        if (state == -2)
        {
            return;
        }
        else if (state == -1)
        {
            continue;
        }
        else
            ;
    }
}

int redeem_transaction(vector<Product> &prod_vect, vector<Customer> &cust_vect, int &prod_index, int &cust_index, float redeem_ratio, string gen_file, string r_transact_file, int &max_rtid)
{
    cout << "Available Products: \n\n";
    display_redeem_product(prod_vect, redeem_ratio);
    cout << "Your current number of reward points is " << cust_vect[cust_index].get_point() << ".\n";
    prod_index = find_prod_by_id(prod_vect, "check");
    if (prod_index == -2)
    {
        return -2;
    }
    else if (prod_index == -1)
    {
        return -1;
    }
    else
        ;

    if (prod_vect[prod_index].get_count() == 0)
    {
        cout << "No item left in stock. Please try another product.\n";
        return -1;
    }
    else if (prod_vect[prod_index].get_price() / redeem_ratio > cust_vect[cust_index].get_point())
    {
        cout << "You do not have enough points to redeem this product.\n";
        return -1;
    }
    else
        ;

    prod_vect[prod_index].set_count(prod_vect[prod_index].get_count() - 1);
    cust_vect[cust_index].set_point(cust_vect[cust_index].get_point() - prod_vect[prod_index].get_price() / redeem_ratio);
    cout << "You have redeem 1 " << prod_vect[prod_index].get_name() << ". Your new number of reward point is " << cust_vect[cust_index].get_point() << ".\n";
    append_to_r_transact(r_transact_file, max_rtid, cust_vect[cust_index].get_id(), prod_vect[prod_index].get_id(), prod_vect[prod_index].get_price(), prod_vect[prod_index].get_price() / redeem_ratio);
    max_rtid++;
    float rw_ratio, rd_ratio;
    get_general(gen_file, rw_ratio, rd_ratio, max_rtid);
    save_general(gen_file, rw_ratio, rd_ratio, max_rtid);
    return -1;
}

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

void append_to_r_transact(string file_name, int &max_tid, string cust_id, string prod_id, float prod_price, float prod_point)
{
    ofstream file;

    file.open(file_name, ios_base::app);

    if (!file)
    {
        cout << "Creating Redeem Transaction save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (max_tid == 0)
    {
        file << "Transaction ID " << id_generator("T0000000000", "T", 10) << endl;
        ;
    }
    else
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

void shop_prod(vector<Product> &prod_vect, vector<Customer> &cust_vect, float reward_ratio, int &max_tid, string config_file, string file_name)
{
    cout << "Please log in to shop or exit\n";

    int cust_index = find_cust_by_id(cust_vect, "check");

    if (cust_index == -1)
        return;
    cout << "\nHello, " << cust_vect[cust_index].get_fname() << " " << cust_vect[cust_index].get_lname() << ".\n";

    map<int, int> shop_cart;
    print_cart(shop_cart, prod_vect);

    cout << "Below is the list of availabe product\n\n";
    display_shop_product(prod_vect);

    while (1)
    {
        int state = add_to_cart(shop_cart, prod_vect);
        if (state == -2)
            break;
        else if (state == -1)
            continue;

        cout << "\nYour current cart\n";
        print_cart(shop_cart, prod_vect);
    }

    // CHECK OUT
    string input;
    while (1)
    {
        float sub_total = print_cart(shop_cart, prod_vect);
        cout << "Your total is: " << sub_total << endl;
        cout << "Points received: " << sub_total * reward_ratio << endl;

        cout << "Checkout ?(y/n): ";
        if (cin >> input)
        {
            if (input == "y")
            {
                float total = 0;
                for (auto pair : shop_cart)
                {
                    // set new cout
                    int new_count = prod_vect[pair.first].get_count() - pair.second;
                    prod_vect[pair.first].set_count(new_count);
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
            else if (input == "n")
            {
                cout << "Cart deleted\n";
                return;
            }
            else
                continue;
        }
    }
}

int add_to_cart(map<int, int> &shop_cart, vector<Product> &prod_vect)
{
    int prod_index;
    while (1)
    {
        cout << "Enter exit to continue to check out\n";
        prod_index = find_prod_by_id(prod_vect, "check");
        if (prod_index == -2) // exit
        {
            return -2;
        }
        else if (prod_index == -1) // not found
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
        cout << "Please enter amount:";
        if (cin >> input)
        {
            if (input == -2) // exit
                return -2;
            else if (input == -1) // choose different product
                return -1;
            if ((input > 0) and (input <= prod_vect[prod_index].get_count()))
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
                cout << "Invalid ammount\n";
                continue;
            }
        }
    }
}

float print_cart(map<int, int> &shop_cart, vector<Product> &prod_vect)
{
    float total = 0;
    cout << endl;
    for (auto pair : shop_cart)
    {
        cout << prod_vect[pair.first].get_name() << ": " << pair.second << " item(s)\n";
        total += prod_vect[pair.first].get_price() * pair.second;
    }
    cout << "Your Sub-Total is: " << total << "\n\n";
    return total;
}

void append_to_s_transact(string config_file, string file_name, int max_tid, map<int, int> &shop_cart, Customer cust, vector<Product> vect, float reward_ratio)
{
    ofstream file;
    file.open(file_name, ios_base::app);
    if (!file)
    {
        cout << "Creating Shopping Transaction save file...\n";
        // Create run_log
        ofstream new_file;
        new_file.open(file_name);
        new_file.close();
    }

    if (max_tid == 0)
    {
        file << "Transaction ID " << id_generator("S0000000000", "S", 10) << endl;
    }
    else
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