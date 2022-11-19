// Name
// Billy Brooks
// Anh Minh Nhat Doan
// Huy Huynh
// Hung Nguyen

#ifndef REWARDMANAGEMENT_H
#define REWARDMANAGEMENT_H

#include <iostream>
#include <vector>

using namespace std;

class Rewardmanagement
{
private:
    int points;
    int amount;
    string gift;
    int shopping_amount;
    float total_points;

public:
    double purchase = 0.0;
    int points = 0;
    int shopping_amount;
    int reward_points;
    int amount;
    string gift;
    void Reward_managment();
    void givenPoints();
    void Reward_managment(vector<Rewardmanagement> &vect, int amount);
};
#endif