//file.h

#include <fstream>//preprocessing directive for file input and output
#include <vector>//preproecessing directve for vector usage
using namespace std;//name change for cin cout
class file{//class defintion of file
public://public member functions 
    void ace(int count[],int& x,int user);//void function prototypes
        //ace function helps determine what value the ace should be 
    void readfile(ifstream& x, vector<string>& usernames, vector<int>& bets);
        //readfile function that gets the first name, last name, and the bet from the ifstream
        //then inputs that info into the vector for the player name and bet
    void output(vector<string>& x,vector<int>& bets,ofstream& y);
        //ouput function outputs the infromatiinon in the vectors of the players name and bets
};