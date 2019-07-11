#include <iostream>
#include <string>
#include "util.h"
#include <Windows.h>

using namespace std;

void instructions(Util &util) {
	cout << "--------------------------------------------------------------------------\n";
	cout << "-----                                                                -----\n";
	cout << "---                         Fixtures Generator                         ---\n";
	cout << "--                                                                      --\n";
	cout << "-                              Mini-Project                              -\n";
	cout << "--                                                                      --\n";
	cout << "----         https://github.com/EdwinWalela/fixture-generator         ----\n";
	cout << "-----                                                                -----\n";
	cout << "--------------------------------------------------------------------------\n";
	cout << "\n\n";
	cout << "--------------------------------- Menu -----------------------------------\n";
	cout << "-                                                                        -\n";
	cout << "- 1. Read File (" << util.getTeamCount() << " Teams loaded)                                 5. Exit -\n";
	cout << "-                                                                        -\n";
	cout << "- 2. Create Fixtures (" << util.getFixturesCount() << " Fixtures generated)                             -\n";
	cout << "-                                                                        -\n";
	cout << "- 3. Generate Report                                                     -\n";
	cout << "-                                                                        -\n";
	cout << "- 4. Display Generated Fixtures                                          -\n";
	cout << "-                                                                        -\n";
	cout << "- Enter Choice : ";
}

int main() {
	SetConsoleTitle(L"Fixtures Generator");
	Util util;
	int choice = 0;
	string file;
	while (choice != 5) {
		instructions(util);
		cin >> choice;
		switch (choice)
		{
		case 1: // Read file
				// Prevent file double reading
			if (util.getTeamCount() <= 0) {
				cout << "- \n- Enter file name (include extension e.g file.csv)\n- \n- ";
				cin >> file; // Input file directory
				util.readFile(file); //Reads teams from input
				cout <<"\n- "<< util.getTeamCount() << " teams have been read from " << file << "\n\n";
			}
			break;
		case 2: // Create Fixtures
				// Prevent multiple generation of fixures
			if (util.getFixturesCount() <= 0) {
				util.createMatches(); // Pairs teams into a match
				util.shuffleMatches();  // Shuffle the generated matches (Fisher-Yates Algorithm)
				util.sortMatches(); // Ensures second legs matches come after all the first legs have been played (Bubble Sort)
				util.createWeekendGames(); // Pairs matches (2 matches per weekend)
				cout <<"\n- "<< util.getFixturesCount() << " fixtures have been generated \n\n";
			}
			break;
		case 3: // Generate Report

			util.writeFile("output.csv"); // Write final result (fixtures) to file
			cout <<"Opening generated Fixtures \n";
			system("start output.csv");
			break;
		case 4:
			util.displayFixtures();
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	cout << "bye\n";
	return 0;
}

