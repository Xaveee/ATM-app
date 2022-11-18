#include <iostream>
#include <vector>
#include <string>

// ******************************************************************************
// Function Name:   input_prod_stock()
// Parameter:       the number of items left in stock of a product
// Return:          1 if success, 0 if exit
// Description:     Function used to get the item in stock when a new product is created
// ******************************************************************************
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
            else
                ;
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

// ******************************************************************************
// Function Name:   input_prod_price()
// Parameter:       the product's price
// Return:          1 if success, 0 if exit
// Description:     Function used to get the price when a new product is created
// ******************************************************************************
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
            else
                ;
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

// ******************************************************************************
// Function Name:   input_prod_description()
// Parameter:       a product's description
// Return:          1 if success, 0 if exit
// Description:     Function used to get the description when a new product is created
// ******************************************************************************
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

// ******************************************************************************
// Function Name:   input_username()
// Parameter:       a customer's username, customer vector
// Return:          1 if success, 0 if exit
// Description:     Function used to get the username when a customer is added
// ******************************************************************************
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

            // VALIDATION
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos)
            {
                cout << "Invalid Input. The username can only contain characters and numbers.\n";
                continue;
            }
            else
                ;

            int first_num_index = input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
            string username_char = input.substr(0, first_num_index);
            string username_num;

            if (first_num_index != string::npos)
                username_num = input.substr(first_num_index);
            else
            {
                username_num = "";
            }

            if ((username_char.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) || (username_char.size() < 8))
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

            // Check unique username
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

// ******************************************************************************
// Function Name:   input_name()
// Parameter:       a customer's first/last name, type "first" or "last"
// Return:          1 if success, 0 if exit
// Description:     Function used to get the names when a customer is added
// ******************************************************************************
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

            // VALIDATION
            if (input.size() > 15)
            {
                cout << "Invalid input. Your " << type << " name cannot contain more than 15 characters.\n";
                continue;
            }
            else
                ;
            if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
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

// ******************************************************************************
// Function Name:   input_year()
// Parameter:       N/A
// Return:          year if success, -1 if exit
// Description:     Function used to get the year of birth of a customer
// ******************************************************************************
int input_year()
{
    int year;
    while (1)
    {
        cout << "Enter your year of birth or -1 to exit: ";
        if (cin >> year)
        {
            if (year == -1)
                return -1;
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
    return year;
}

// ******************************************************************************
// Function Name:   input_month()
// Parameter:       N/A
// Return:          month if success, -1 if exit
// Description:     Function used to get the month of birth of a customer
// ******************************************************************************
int input_month()
{
    int month;
    while (1)
    {
        cout << "Enter your month of birth or -1 to exit: ";
        if (cin >> month)
        {
            if (month == -1)
                return -1;
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
    return month;
}

// ******************************************************************************
// Function Name:   input_day()
// Parameter:       maximum day in that month
// Return:          day if success, -1 if exit
// Description:     Function used to get the day of birth of a customer
// ******************************************************************************
int input_day(int day_max)
{
    int day;
    while (1)
    {
        cout << "Enter your day of birth or -1 to exit: ";
        if (cin >> day)
        {
            if (day == -1)
                return -1;
            else
                ;
            if (day < 0)
            {
                cout << "Your day of birth cannot be smaller than 0.\n";
                continue;
            }
            else
                ;

            // Day validation
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
    return day;
}

// ******************************************************************************
// Function Name:   get_day_max()
// Parameter:       month and year of birth
// Return:          maximum day of that month
// Description:     Function used to get the maximum day of a month
// ******************************************************************************
int get_day_max(int month, int year)
{
    vector<int> thirty_one = {1, 3, 5, 7, 8, 10, 12}; // Months with 31 days
    vector<int> thirty = {4, 6, 9, 11};               // Months with 30 days
    int day_max = 0;

    // if month has 30 days
    for (auto &m : thirty)
    {
        if (month == m)
        {
            day_max = 30;
        }
        else
            ;
    }
    // if month has 31 days
    for (auto &m : thirty_one)
    {
        if (month == m)
        {
            day_max = 31;
        }
        else
            ;
    }
    // February
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

    return day_max;
}

// ******************************************************************************
// Function Name:   dob_to_string()
// Parameter:       year, month, day of birth
// Return:          dob in format "MM-DD-YYYY"
// Description:     Function used to convert the dob of a customer to string form
// ******************************************************************************
string dob_to_string(int year, int month, int day)
{
    // Convert DOB to string
    string s_year, s_month, s_day;

    // Pad year
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

    // Pad month
    if (month < 10)
    {
        s_month = "0" + to_string(month);
    }
    else
    {
        s_month = to_string(month);
    }

    // Pad day
    if (day < 10)
    {
        s_day = "0" + to_string(day);
    }
    else
    {
        s_day = to_string(day);
    }
    string dob = s_month + "-" + s_day + "-" + s_year;
    return dob;
}

// ******************************************************************************
// Function Name:   input_dob()
// Parameter:       a customer's date of birth
// Return:          1 if success, 0 if exit
// Description:     Function used to get the customer's dob when a customer is added
// ******************************************************************************
int input_dob(string &dob)
{
    // year
    int year;
    year = input_year();
    if (year == -1)
    {
        return 0;
    }
    else
        ;

    // month
    int month;
    month = input_month();
    if (month == -1)
    {
        return 0;
    }
    else
        ;

    // day
    int day;
    int day_max = get_day_max(month, year); // Max day in a month
    day = input_day(day_max);
    if (day == -1)
    {
        return 0;
    }
    else
        ;

    dob = dob_to_string(year, month, day);
    return 1;
}

// ******************************************************************************
// Function Name:   input_cred_num()
// Parameter:       a customer's credit card number, customer vector
// Return:          1 if success, 0 if exit
// Description:     Function used to get the credit card number when a customer is added
// ******************************************************************************
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

            // VALIDATION
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

            // Add the dashes between the numbers
            input = input.substr(0, 4) + "-" + input.substr(4, 4) + "-" + input.substr(8, 4);

            // Check duplicate
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

// ******************************************************************************
// Function Name:   input_reward_point()
// Parameter:       a customer's initial reward point
// Return:          1 if success, 0 if exit
// Description:     Function used to get the initial reward point when a customer is added
// ******************************************************************************
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

// ******************************************************************************
// Function Name:   input_ratio()
// Parameter:       type of ratio "reward" or "redeem"
// Return:          the ratio
// Description:     Function used to get the ratio from shop manager
// ******************************************************************************
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
