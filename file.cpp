//file.cpp

#include"file.h"//includes the file class
#include <iostream>//preprocessing directive for input and output
#include<fstream>//preprocessing directive for use of the file input and output
#include <vector>//preprocessing directive to use vector function 
using namespace std;//name change for cin and cout

void file::output(vector<string>& x,vector<int>& bets,ofstream& y)
{
    for(size_t i = 0; i < x.size(); ++i)
        cout << "Player: " << x[i] << ", Bet: $" << bets[i] << endl;
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
        string name = first + " " + last;
        usernames.push_back(name);
        bets.push_back(money);
    }
}
