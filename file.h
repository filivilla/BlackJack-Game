//file.h

#include <fstream>
#include <vector>
using namespace std;
class file{
public:
    void ace(int count[],int& x,int user);
    void readfile(ifstream& x, vector<string>& usernmaes, vector<int>& bets);
    void output(vector<string> x,vector<int> bets);
};