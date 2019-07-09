// @TODO: read input from file

#include <iostream>
#include "util.h"

using namespace std;

int main(){
    Util util;
    
    util.readFile("input.csv");
    cout<<endl<<endl<<endl;
    util.createMatches();
    util.shuffleMatches();
    util.createWeekendGames();
    util.displayFixtures();
    
    return 0;
}