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
    return line.substr(index, line.length() - 1);
}

void read_cust_to_vect(string file_name, vector<Customer> &vect)
{
    string a;

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

    if (!getline(file, a)) // File is empty
    {
        cout << "empty" << endl;
    }
    else // Start parsing to vect
    {
        do
        {
            string id;
            string username;
            string first_name;
            string last_name;
            string dob;
            float total_points;

            id = parse_line(a);
            getline(file, a);

            username = parse_line(a);
            getline(file, a);

            first_name = parse_line(a);
            getline(file, a);

            last_name = parse_line(a);
            getline(file, a);

            dob = parse_line(a);
            getline(file, a);

            total_points = stof(parse_line(a));
            getline(file, a);

            Customer cust(id,
                          username,
                          first_name,
                          last_name,
                          dob,
                          total_points);
            vect.push_back(cust);
            // cout << index << endl;
        } while (getline(file, a));
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