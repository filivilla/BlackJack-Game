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

    int num_players;//number of players,declared variable
    vector<int> score;//declares a vector of int for score 
    vector<int> bet;//declares a vector of integers for bet
    vector<string> name;//declares a vector of string for usernames
    int dealer;//dealers score , variable declared

    if(!players)//checks if the file was opened or not
    {
        cout << "File not found";
        return 1;//terminates the program 
    }//end if 

    //**function to input the name and bet to the names and bets vector */
    object.dealer(dealer,cards);//function call from class object
    object.readfile(dealer,cards,players,name,bet,score);//function call for readfile
    object.input(name,bet,score,num_players);//function call for input, gets input from user and populates the vectors
    object.start(name,bet,score,cards,dealer);
    object.BubbleSort(name,bet,score);
    //**function to output the name and bet vectors to the terminal */
    object.output(name,bet,leaderboard,score);//function call for file class
    
    

    return 0;//returns 0

}//end main 