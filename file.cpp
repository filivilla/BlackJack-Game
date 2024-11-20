//file.cpp

#include"file.h"
#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

void file::output(vector<string> x,vector<int> bets)
{
    for(size_t i = 0; i < x.size(); ++i)
        cout << "Player: " << x[i] << ", Bet: " << bets[i] << endl;
}

void file::ace(int count[], int &x, int user)
{
    if(count[user] + 11 > 21)
        x = 1;
    else
        x = 11;
}

void file::readfile(ifstream &x, vector<string> &usernames, vector<int> &bets)
{
    string first,last;
    int money;

    while (x >> first >> last >> money)
    {
        string name = first + last;
        usernames.push_back(name);
        bets.push_back(money);
    }
}
