#ifdef STRUCT_H
#define STRUCT_H

struct deck{//struct deck to hold the suits 
int x;//declares x to be used as ace value 
//**Creates the cards and array for the cards infinite cards */
int Hearts[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, x}//heart suit
;int Spades[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, x}; //spades
int Clubs[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, x};//clubs
int Diamonds[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, x}; //diamons
};

#endif 