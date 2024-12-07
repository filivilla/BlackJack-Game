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
    cout << left << setw(max_length) <<"Player"<< right << setw(10) << "Bet" << endl;
    y << left << setw(max_length) <<"Player"<< right << setw(10) << "Bet" << endl;
    //inputs the header into the outfile 

    for(size_t i = 0; i < x.size(); ++i){
    //for loops through the number of elements in the vector of names
    //which is the same size as the bets 
    //**size_t ensures that it can store the maximum number elemetns for array 
        cout << left << setw(max_length) << x[i] << right << setw(10) << "$" << bets[i] << endl;//displays in terminal and file 
        y << left << setw(max_length) << x[i] << right << setw(10) << "$" << bets[i] << endl;
        //inputs the leaderboard into write file
    }//end for 
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

void file::readfile(int &dealer,deck card,ifstream &x, vector<string> &usernames, vector<int> &bets, vector<int> &score)
{//void function definiton, gets info from file, the info has already been checked so no need for error handling
    string first,last;//declared variables 
    int money;
    x >> first >> last >> money;
    string name = first + " " + last;//intialized name with first and last
    int hand;//random players hand from file 
    hand = 0;//intializes dealer
    while(hand < 17)//continues until dealer has 17 or more cards
    {
        int postion = rand() % 13;//draws the card
        if(postion == 12)//checks for ace
            ace(hand);//calls the function ace
        else
            hand += card.Cards[postion];//adds the card to the random players hand 
        if(hand > 21)//checks if the player busted
        {
            cout << name << " busted"<<endl;
            hand = 0;//sets the player to 0
            money = 0;
            break;//stops the while loop
        }//end if
    }//end while
    if(hand >= 17 && hand <= 21)//checks to show random players hand to the players
    {
        cout << name << " stands with a hand of " << hand << endl;//outputs the score for random player
        if(hand > dealer)//checks if they won 
        {
            cout << name << " won against the dealer." << endl;
            money *= 1.5;
        }//end if
        else //if random player loses
        {
            cout << name << " lost to the dealer." << endl;
            money = 0;//loses their money 
        }//end else
    }//end if
    usernames.push_back(name);//inserts the new value to the end of the vector
    bets.push_back(money);//inserts the new value at the end of the vector
    score.push_back(hand);//inserts 0 to match name and money position 
    //**.push_back() inserts a value to the end of the vector */
}//end readfile

void file::input(vector<string>& x,vector<int>& bets,vector<int>& score, int &num_players)
{//void function definiton 
    string name;//declared variables 
    int bet;
    cout << "Enter number of players: ";
    cin >> num_players;//enter number of players 
    assert(num_players > 0 && "There must be at least one player");
    for(int i = 0; i < num_players; i++)//popluations the vectors names,bets, and score
    {//for starts, continues until i is equal to numplayers then incriments
        cin.ignore();//clears the buffer 
        cout << "Player " << i+1 << " enter your name: "; 
        getline(cin,name);//gets name 
        assert(!name.empty() && "Name cannot be empty");//checks if user entered name 
        cout << "Enter your bet: $";
        cin >> bet;//gets bet
        assert(bet > 0 && "Bet must be greater than zero");//chekcs if bet is not 0 or negative 
        x.push_back(name);//inserts name in the vector in the back
        bets.push_back(bet);//inserts bet in the vector in the back
        score.push_back(0);//inserts 0 in the vector in the back
    }//end for
}//end input 

void file::start(vector<string>& name,vector<int> &bets, vector<int> &score,deck cards,int &dealer)
{
    for(size_t i = 0; i < bets.size(); ++i)//loops through all the players 
    {
        bool HIT = true;//declared and intialized variables
        int playerhand = 0;
        char choice;
        cout << name[i] << "'s turn" << endl;//displayed the current players name 
        while(HIT)//loops until the player stands 
        {
            cout << "Current hand is " << playerhand << endl;//shows the players current hand 
            cout << "DO you want to Hit (H) or Stand (S)? ";
            cin >> choice;//asks the player if they want to hit or stand 
            assert((toupper(choice) == 'S' || toupper(choice) == 'H') && "Invalid input, please enter H or S");//error handling checks if user entered S or H 
            if(toupper(choice) == 'S')//stops the loop if player wants to stand 
                break;
            int random = rand() % 13;//gets the first card
            if(random == 12)//checks if its an ace 
                ace(playerhand);//function call if ace
            else//adds the card to players hand if its not an ace
                playerhand += cards.Cards[random];
            cout << "You drew a card, your new hand is " << playerhand << endl;

            if (playerhand > 21)//checks if the player busted or if they lost to the dealers hand 
            {
                cout << "You lost"<< endl;
                score[i] = 0;//makes the bet and score 0 
                bets[i] = 0;
                HIT = false;//then ends the loop 
            }//end if 
            
        }//end while 
        if(playerhand <= 21 && (playerhand > dealer || dealer > 21))
        {//checks player hand to make sure that they won 
            score[i] = playerhand;//adds player hand to their score 
            bets[i] = bets[i] * 1.5;//adds to their bet
            cout << name[i] << "won: $" << bets[i] << endl;//then displays that they won 
        }//end if 
        else//checks if score is less than the dealer
        {
            cout << "You lost"<< endl;
            score[i] = 0;//makes the bet and score 0 
            bets[i] = 0;
        }//end if 
    }//end for 
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
            if (bets[j] < bets[j + 1]) {
                // Swap bets
                swap(bets[j], bets[j + 1]);//swap function 
                //swap swaps the values of the two vecotrs 
                // Swap names
                swap(name[j], name[j + 1]);//swap function 
            }//end if 
        }//end for
    }//end for 
}//end Bubblesort