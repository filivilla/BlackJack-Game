//file.cpp

#include"file.h"//includes the file class
#include <iostream>//preprocessing directive for input and output
#include<fstream>//preprocessing directive for use of the file input and output
#include <vector>//preprocessing directive to use vector function 
#include <cassert>//preprocessing directive for assert
#include <iomanip>//preprocessind directive for formatting 
#include <ctime>//preprocessing dricetive for time 
#include<random>//preprocessing directive for random 
#include"struct.h"//enable to use struct deck
#include <cctype>//preprocessingd directive for toupper
using namespace std;//name change for cin and cout

void file::output(vector<string> &x,vector<int> &bets,ofstream &y, vector<int> &score)
{//void function defintion 
//** vectors passed as string to keep memory short*/
    int max_length = 0;//assigsn max_length with zero 

    for(size_t r = 0; r < x.size(); ++r){//calculates the amount of space needed 
    //x.size() is datatype of size_t so makeing r the same data type
    //must convert the vector to int to be able to compare the two values 
        if(max_length < static_cast<int>(x[r].length()))//checks if max length is less than the length 
            max_length = static_cast<int>(x[r].length());//changes max_length
    }//end for 
    max_length += 15;//finds the length plus 15

    y << left << setw(max_length) <<"Player"<< right << setw(10) << "Bet" << endl;
    //inputs the header into the outfile 

    for(size_t i = 0; i < x.size(); ++i)
    //for loops through the number of elements in the vector of names
    //which is the same size as the bets 
    //**size_t ensures that it can store the maximum number elemetns for array 
        y << left << setw(max_length) << x[i] << right << setw(10) << "$" << bets[i] << endl;
        //inputs the leaderboard into write file 
}//end of output function


void file::ace(int &dealer)//changes the original hand 
{//void function definiton 
    int x;//declared variable 
    if(dealer + 11 > 21)//checks if dealer busts when ace is 11
        x = 1;//assigns x wtih 1
    else//if dealer does not bust then x is 11
        x = 11;
    dealer += x;//adds ace to hand 
}//end ace

void file::readfile(ifstream &x, vector<string> &usernames, vector<int> &bets, vector<int> &score)
{//void function definiton 
    string first,last;//declared variables 
    int money;
    while (x >> first >> last >> money)
    {//while continues when file has still information 
        string name = first + " " + last;//intialized name with first and last
        usernames.push_back(name);//inserts the new value to the end of the vector
        assert(money != 0 && "Bet must be greater than zero");//assert if false terminate program if true continues 
        bets.push_back(money);//inserts the new value at the end of the vector
        score.push_back(0);//inserts 0 to match name and money position 
    //**.push_back() inserts a value to the end of the vector */
    }//end while 
}//end readfile

void file::input(vector<string>& x,vector<int>& bets,vector<int>& score, int &num_players)
{//void function definiton 
    string name;//declared variables 
    int bet;
    cout << "Enter number of players:";
    cin >> num_players;//enter number of players 
    assert(num_players > 0 && "There must be at least one player");
    for(int i = 0; i < num_players; i++)//popluations the vectors names,bets, and score
    {//for starts, continues until i is equal to numplayers then incriments
        cout << "Enter your bet:";
        cin >> bet;//gets bet
        assert(bet > 0 && "Bet must be greater than zero");//chekcs if bet is not 0 or negative 
        cin.ignore();//clears the buffer 
        cout << "Enter your name:"; 
        getline(cin,name);//gets name 
        x.push_back(name);//inserts name in the vector in the back
        bets.push_back(bet);//inserts bet in the vector in the back
        score.push_back(0);//inserts 0 in the vector in the back
    }//end for
}//end input 

void file::start(vector<string>& name,vector<int> &bets, vector<int> &score,deck cards,int &dealer)
{
    for(size_t i = 0; i < bets.size(); ++i)
    {
        bool HIT = true;
        int playerhand = 0;
        char choice;
        cout << name[i] << "turn" << endl;
        while(HIT)
        {
            cout << "Current hand" << playerhand << endl;
            cout << "DO you want to Hit (H) or Stand (S)?";
            cin >> choice;
            if(toupper(choice) == 'S')
                break;
            int random = rand() % 13;
            if(random == 12)
                ace(playerhand);
            else
                playerhand += cards.Cards[random];
            cout << "You drew the card, your new hand is " << playerhand << endl;

            if (playerhand > 21 || playerhand <= dealer)
            {
                cout << "You lost"<< endl;
                score[i] = 0;
                bets[i] = 0;
                HIT = false;
            }
            
        }
        if(playerhand <= 21 && playerhand > dealer)
        {
            score[i] = playerhand;
            bets[i] = bets[i] * 1.5;
            cout << name[i] << "won" << bets[i] << endl;
        }
        
    }
}
// end start

void file::dealer(int &dealer, deck card)
{//dealer hand score
    dealer = 0;//intializes dealer
    while(dealer < 17)//continues until dealer has 17 or more cards
    {
        int postion = rand() % 13;//draws the card
        if(postion == 12)//checks for ace
            ace(dealer);//calls the function ace
        else
            dealer += card.Cards[postion];//adds the card to the dealers hand 
        if(dealer > 21)//checks if the dealer busted
        {
            cout << "Dealer busted"<<endl;
            dealer = 0;//sets the dealer to 0
            break;//stops the while loop
        }
    }//end while
    if(dealer >= 17 && dealer <= 21)//checks to show dealers hand to the players
        cout << "Dealer stands with a hand of " << dealer << endl;//outputs the score for dealer
}//end dealer

void file::BubbleSort(vector<string>& name, vector<int>& bets, vector<int>& score)
{//bubble sort
    int n = score.size();
    //intializes the total number of players
    
    // Bubble sort: iterate through each player's score
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            // If current score is smaller than the next score, swap the scores, bets, and names
            if (score[j] < score[j + 1]) {
                // Swap scores
                swap(score[j], score[j + 1]);
                
                // Swap bets
                swap(bets[j], bets[j + 1]);
                
                // Swap names
                swap(name[j], name[j + 1]);
            }
        }
    }
}