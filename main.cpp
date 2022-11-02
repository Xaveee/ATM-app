#include <iostream>

using namespace std;

int main()
{
    cout << "Customer Reward System\n\n";

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
            cout << choice << endl;
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