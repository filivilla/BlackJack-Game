//struct.h

#ifndef STRUCT_H//checks if struct.h is defined
#define STRUCT_H//definies struct

struct deck{//struct deck to hold the suits 
int x = 11;//declares x to be used as ace value 
//**Creates the cards and array for the cards infinite cards */
int Cards[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, x};//cards no suits becauses its infinite 
};
#endif //ends sequence