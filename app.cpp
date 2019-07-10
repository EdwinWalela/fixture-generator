// @TODO: read input from file

#include <iostream>
#include "util.h"

using namespace std;

int main(){
    Util util;
    
    util.readFile("input.csv"); //Reads teams from input
    util.createMatches(); // Pairs teams into a match
    util.createWeekendGames(); // Pairs matches ( 2 matches per weekend)
    util.shuffleMatches();  // Shuffle the generated matches (Fisher-Yates Algorithm)
    util.sortMatches(); // Ensures second legs matches come after all the first legs have been played (Bubble Sort)
    util.writeFile("output.csv");
    
    return 0;
}