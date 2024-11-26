//file.cpp

#include"file.h"//includes the file class
#include <iostream>//preprocessing directive for input and output
#include<fstream>//preprocessing directive for use of the file input and output
#include <vector>//preprocessing directive to use vector function 
using namespace std;//name change for cin and cout

void file::output(vector<string>& x,vector<int>& bets,ofstream& y)
{//void function defintion 
//** vectors passed as string to keep memory short*/
    for(size_t i = 0; i < x.size(); ++i)//for loops through the number of elements in the vector of names
    //which is the same size as the bets 
    //**size_t ensures that it can store the maximum number elemetns for array 
        cout << "Player: " << x[i] << ", Bet: $" << bets[i] << endl;
        //outputs the elements i for the name and bets vector 
}//end output

void file::ace(int count[], int &x, int user)
{//void function definiton 
    if(count[user] + 11 > 21)
        x = 1;
    else
        x = 11;
}

void file::readfile(ifstream &x, vector<string> &usernames, vector<int> &bets)
{//void function definiton 
    string first,last;//declared variables 
    int money;

    while (x >> first >> last >> money)
    {//while continues when file has still information 
        string name = first + " " + last;//intialized name with first and last
        usernames.push_back(name);//intserts the new value to the end of the vector
        bets.push_back(money);//inserts the new value at the end of the vector
    //**.push_back() inserts a value to the end of the vector */
    }//end while 
}//end readfile
