// @TODO: read input from file

#include <iostream>
#include <string>
#include "util.h"

using namespace std;


void instructions(Util &util){
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"-----                                                                -----\n";
    cout<<"---                         Fixtures Generator                         ---\n";
    cout<<"--                                                                      --\n";
    cout<<"---                            Mini-Project                            ---\n";
    cout<<"-----                                                                -----\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"\n\n";
    cout<<"--------------------------------- Menu -----------------------------------\n";
    cout<<"-                                                                        -\n";
    cout<<"- 1. Read File ("<<util.getTeamCount()<<" Teams loaded)                        4. Documentation -\n";
    cout<<"-                                                                        -\n";
    cout<<"- 2. Create Fixtures ("<<util.getFixturesCount()<<" Fixtures generated)            5. Exit          -\n";
    cout<<"-                                                                        -\n";
    cout<<"- 3. Generate Report                                                     -\n";
    cout<<"-                                                                        -\n";
    cout<<"-                                                                        -\n";
    cout<<"- Enter Choice : ";
}

int main(){
    Util util;
    int choice;
    string file;
    while(choice != 5){
        instructions(util);
        cin>>choice;
        switch (choice)
        {
            case 1: // Read file
            // Prevent file double reading
                if(util.getTeamCount() <= 0){
                    cout<<"- \n- Enter file name (include extension e.g file.csv)\n- \n- ";
                    cin>>file; // Input file directory
                    util.readFile(file); //Reads teams from input
                }
                break;
            case 2: // Create Fixtures
            // Prevent multiple generation of fixures
                if(util.getFixturesCount() <= 0){
                    util.createMatches(); // Pairs teams into a match
                    util.shuffleMatches();  // Shuffle the generated matches (Fisher-Yates Algorithm)
                    util.sortMatches(); // Ensures second legs matches come after all the first legs have been played (Bubble Sort)
                    util.createWeekendGames(); // Pairs matches (2 matches per weekend)
                }
                break;
            case 3: // Generate Report
                cout<<"- \n- Enter output file name (or 0 to use default output.csv file)\n- \n- ";
                cin>>file; // output file directory
                util.writeFile(file); // Write final result (fixtures) to file
                break;
            case 4: // Documentation
                break;    
            default:
                break;
        }
        system("cls");
    }

   return 0;
}