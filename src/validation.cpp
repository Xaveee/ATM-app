#include <iostream>
#include <vector>
#include <string>

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
