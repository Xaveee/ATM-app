#include <iostream>
//#include "Rewardmanagement.h"

using namespace std;
int Rewardpoints(double purchase, double rate);
double purchase = 0.0;
int points = 0;
int shopping_amount;
int reward_points;
string gift;

void Rewardmanagment(int points, int amount, float total_points)
{
    cout << "How many points are avaliable?";
    cin >> points;
    if (points >= 0 && amount >= 0)
    {
        if (points > 0 && amount > 0)
        {
            if (points % 2 == 0)

            {
                if (points >= 100)
                    cout << "You can redeem a gift.";
                else
                    cout << "You cannot redeem a gift.";
            }
            else
                cout << "You cannot redeem a gift.:";
        }
        else
            cout << "You cannot redeem a gift.";
    }
    else
        cout << "Invalid input.";
}

void givenPoints(int points, int shopping_amount)
{
    if (shopping_amount >= 100)
    {
        points = 10;
    }
    else if (shopping_amount >= 50)
    {
        points = 5;
    }
    else
    {
        points = 0;
    }
}

void redeemPoints(int points, string gift)
{
    if (points >= 100)
    {
        gift = "Ipad";
    }
    else if (points >= 50)
    {
        gift = "Gift Card";
    }
    else
    {
        gift = "none";
    }
}
