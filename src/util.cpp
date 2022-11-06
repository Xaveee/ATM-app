#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

            float total_points = stof(parse_line(line));
            getline(file, line);

            Customer cust(id,
                          username,
                          first_name,
                          last_name,
                          dob,
                          total_points);
            vect.push_back(cust);
            // cout << index << endl;
        } while (getline(file, line));
    }
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
void show_cust_by_id(vector<Customer> &vect)
{
    string input;
    while (1)
    {
        cout << "Enter id or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit")
                break;
            else
            {
                bool found = false;
                for (int i = 0; i < vect.size(); i++)
                {
                    if (vect[i].get_id() == input)
                    {
                        vect[i].show_cust();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Customer not Found\n";
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

void show_prod_by_id(vector<Product> &vect)
{
    string input;
    while (1)
    {
        cout << "Enter product id or exit: ";
        if (cin >> input) // Check input type
        {
            // validate input
            if (input == "exit")
                break;
            else
            {
                bool found = false;
                for (int i = 0; i < vect.size(); i++)
                {
                    if (vect[i].get_id() == input)
                    {
                        vect[i].show_prod();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Product not Found\n";
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