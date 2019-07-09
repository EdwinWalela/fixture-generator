// @TODO: read input from file

#include <iostream>
#include "util.h"

using namespace std;

int main(){
    Util util;
    
    util.readFile("input.csv"); //Reads teams from input
    util.createMatches(); // Pairs teams into a match
    util.createWeekendGames(); // Pairs matches ( 2 matches per weekend)
    util.displayFixtures(); // Display Final Result
    
    return 0;
}