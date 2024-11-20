//file.cpp

#include"file.h"
#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

void ace(int count[], int size, int& x,int user)
{
    if(count[user] + 11 > 21)
        x = 1;
    else
        x = 11;
}
void readfile(ifstream& x, vector<string>& usernames, vector<int>& bets)
{
    string name;
    int money;

    while (x >> name >> money)
    {
        usernames.push_back(name);
        bets.push_back(money);
    }
}

void output(const vector<string>& x,const vector<int>& bets)
{
    for(size_t i = 0; i < x.size(); ++i)
        cout << "Player: " << x[i] << ", Bet: " << bets[i] << endl;
}