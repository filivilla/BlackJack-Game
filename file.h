//file.h

#include <fstream>//preprocessing directive for file input and output
#include <vector>//preproecessing directve for vector usage
#include "struct.h"//includes the struct deck
using namespace std;//name change for cin cout
class file{//class defintion of file
public://public member functions 
    void ace(int &dealer);//void function prototypes
        //ace function helps determine what value the ace should be then adds it to hand 
    void readfile(int &dealer,deck card,ifstream& x, vector<string>& usernames, vector<int>& bets,vector<int>& score);
        //readfile function that gets the first name, last name, and the bet from the ifstream
        //then inputs that info into the vector for the player name and be also score
    void output(vector<string>& x,vector<int>& bets,ofstream& y, vector<int>& score);
        //ouput function outputs the infromatiinon in the vectors of the players name and bets and score
    void input(vector<string>& x,vector<int>& bets,vector<int>& score, int &numplayers);
        //gets the input from the diffrent players of their name,bet and score then inputs that into the vector
    void start(vector<string>& name,vector<int>& bets,vector<int>& score,deck card,int &dealer);
        //starts the game so that the players start collecting cards from random 
        //will make the players that busted or went over 21 or went below the dealer score 0
    void BubbleSort(vector<string>& name,vector<int>& bets,vector<int>& score);
        //sorts the vectors from highest score to lowest score 
    void dealer(int& dealer, deck card);
    //function to get the dealers hand 
};