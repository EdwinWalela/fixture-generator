// @TODO: read input from file

#include <iostream>
#include "util.h"

using namespace std;

int main(){
    Util util;

    util.readFile("input.csv");
    util.createMatches();
    util.createWeekendGames();
    util.displayFixtures();
    
    return 0;
}