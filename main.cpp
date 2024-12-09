//Black Jack Game
//main.cpp
#include <iostream>//preprocessing directive for input and output
#include <iomanip>//preprocessing directive for formatting 
#include <ctime>//preporcessing directve for time usage
#include <random>//preporcessing directive for random function
#include <string>//preprocessing directive for string functions
#include <fstream>//preprocessing directive for file functions 
#include"file.h"//access to class 
#include <cassert>//preprocessing directive for usage of assert
#include <vector>//preprocessing directive to include vector 
#include"struct.h"//allows the usage of the struct deck
using namespace std;//name change for cin and cout


int main()//header file for main function 
{
    srand(time(0));//seeds rand with time 0 at the start, in main which allows it be constnat for the functions 
    file object;//object for the class 

    ifstream players("Players.txt");//reading file for other people playing 
    ofstream leaderboard("Leaderboard.out");//file for the outputed scoredbard

    deck cards;//struct object to be able to use the different sets 
    char choice;//choice on what game to play 
    int num_players;//number of players,declared variable
    vector<int> score;//declares a vector of int for score 
    vector<int> bet;//declares a vector of integers for bet
    vector<string> name;//declares a vector of string for usernames
    int dealer;//dealers score , variable declared
    bool again = true;//play again 
    if(!players)//checks if the file was opened or not
    {
        cout << "File not found";
        return 1;//terminates the program 
    }//end if 

    cout << "Welcome to Filiberto's casino! " << endl << "What game would you like to play:" << endl;
    cout << "BlackJack(B), Slotes(S) or Roulette(R)?"<< endl;
    cin >> choice;//asks the player for input to choose between three games 
    choice = toupper(choice);//captilizes the choice
    //if invalid input outputs message checks to make sure a valid answer was inputed
    assert((choice == 'B' || choice == 'S' || choice == 'R') && "Please enter a valid option from those three");
    if(choice == 'B')//if they picked blackjack
        cout << "You chose BlackJack! Welcome" << endl;
    else{//if they picked any other game 
        cout << "Under maintance, come back later" << endl;
        return -1;//stops program 
    }//end else
    //**function to input the name and bet to the names and bets vector */
    while (again)//continues until the player wants to end the game 
    {
        object.dealer(dealer,cards);//function call from class object
        object.input(name,bet,score,num_players);//function call for input, gets input from user and populates the vectors
        object.start(name,bet,score,cards,dealer);//function call to start the game and draw cards for players 
        object.readfile(dealer,cards,players,name,bet,score);//function call for readfile
        object.BubbleSort(name,bet,score);//function call to sort the vectors and prepare for outputting them 
        //**function to output the name and bet vectors to the terminal */
        object.output(name,bet,leaderboard,score);//function call for file class
        cout << "Would you like to play again? Y/N" << endl;
        cin >> choice;//gets choice whether to end the game 
        choice = toupper(choice);//captilaize
        //makes sure answer is valid 
        assert((choice=='Y' || choice == 'N') && "Please enter a valid answer");
        if(choice == 'N')//ends game 
        {
            again = false;
            cout << "Ending game" << endl;
        }//end if 
        else{//resets the game and continues the while loop
            cout << "Reseting for next game" << endl;
            score.clear();
            bet.clear();
            name.clear();
    }//end while 
    

    return 0;//returns 0

}//end main 