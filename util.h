//@ TODO: File opening error checking

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> // time

struct Team
{
    std::string name;
    std::string town;
    std::string stadium;
};

struct Match
{
    Team home;
    Team away;
    bool derby;
    int leg;
};

struct Weekend
{
    Match matches[2];
};

class Util{
    private:
    bool writtenToFile = false;
    std::ifstream inputStream; 
    std::ofstream outputStream;
    std::vector<Team> teams; // List of all teams
    std::vector<Match> matches; // List of all mathces (90)
    std::vector<Weekend> weekendGames; // List of all fixtures (45)
    bool havePlayedBefore(Team a, Team b);

    public:
    void readFile(std::string);
    void writeFile(std::string);

    void createMatches();
    void createWeekendGames();
    void shuffleMatches();
    void sortMatches();

    void displayFixtures();
    void displayMatches();
    void printTeams();
    int getFixturesCount();
    int getTeamCount();

};

// Read input from file
void Util::readFile(std::string _dir){
    // Open target file
    inputStream.open(_dir,std::ios::in);
    std::string str;
    getline(inputStream,str,'\n');
    /* --- Manipulate data  --- */
    while(!inputStream.eof()){
        std::string name,town,stadium;
        getline(inputStream,name,',');
        getline(inputStream,town,',');
        getline(inputStream,stadium,'\n');

        Team t;
        t.name = name;
        t.town = town;
        t.stadium = stadium;
        teams.push_back(t);
    }
    // Close target file
    inputStream.close();
}
// Write output to file
void Util::writeFile(std::string _dir){
    if(_dir.length()<2){
        _dir = "output.csv";
    }
    if(!writtenToFile){
        writtenToFile = true;
        // Open target file
        outputStream.open(_dir,std::ios::trunc);
        outputStream<<"Derby,Game Week,Leg,Home,Away,Town,Stadium\n";
        /* --- Manipulate data --- */
        for(int i = 0; i < weekendGames.size(); i++){
            for(int j = 0; j < 2; j++){
                std::string homeName,awayName,stadium,town;
                std::string derby = weekendGames.at(i).matches[j].derby ? "Derby" : "-";
                int leg;
                // Extract fields from list
                homeName = weekendGames.at(i).matches[j].home.name;
                awayName = weekendGames.at(i).matches[j].away.name;
                stadium = weekendGames.at(i).matches[j].home.stadium;
                town = weekendGames.at(i).matches[j].home.town;
                leg = weekendGames.at(i).matches[j].leg;
                
                // Write values to file
                outputStream<<derby<<","<<i+1<<","<<leg<<","<<homeName<<","<<awayName<<","<<town<<","<<stadium<<"\n";
            }
        }

        outputStream.close();
    }
}
// Print list of teams on console
void Util::printTeams(){
    for(int i = 0; i < teams.size(); i++){
        std::cout<<teams.at(i).name<<",";
        std::cout<<teams.at(i).town<<",";
        std::cout<<teams.at(i).stadium<<std::endl;
    }
}
// Pairs teams into a match
void Util::createMatches(){
    Match derby;
    for(int i = 0; i < teams.size(); i++){
        Team currentTeam = teams.at(i); // Hold team in a variable
        // Iterate through all teams
        for(int j = 0; j < teams.size(); j++){
            // If the teams are the same continue iterating
            if(currentTeam.name == teams.at(j).name){
                continue;
            }else
            // If teams are from same town, hold the teams in a temporary derby variable
            if(currentTeam.town == teams.at(j).town){
                derby.home = currentTeam;
                derby.away = teams.at(j);
                if(havePlayedBefore(currentTeam,teams.at(j))){
                    derby.leg = 1;
                }else{
                    derby.leg = 2;
                }
                derby.derby = true;
            }else{
                Match match;
                match.home = currentTeam;
                match.away = teams.at(j);
                // Go through all matches checking if both teams have played before
                if(havePlayedBefore(currentTeam,teams.at(j))){
                    match.leg = 1;
                }else{
                    match.leg = 2;
                }
                match.derby = false;
                matches.push_back(match);
            }
        }
        // Add derby match after the current team has already played with all other teams
        matches.push_back(derby);
    }
}
// Print matches to std::cout
void Util::displayMatches(){
    for(int i = 0; i < matches.size(); i++){
        std::cout<<"\n--------------match #"<<i+1<<"--------------\n";
        std::cout<<matches.at(i).home.name<<" vs "<<matches.at(i).away.name;
        std::cout<<"\n---------------------------------------\n";
    }
}
// Pairs matches ( 2 matches per weekend)
void Util::createWeekendGames(){
    for(int i = 0; i < matches.size()-1; i+=2){
        Weekend weekend;
        weekend.matches[0] = matches.at(i);
        weekend.matches[1] = matches.at(i+1);
        weekendGames.push_back(weekend);
    }
}
// Shuffle the generated matches (Fisher-Yates Algorithm)
void Util::shuffleMatches(){
    srand(time(NULL)); // Initialize random seed
    for(int i = matches.size()-1; i > 0; i--){
        // Generate random number between 0 and i
        int randomIndex = rand() % i + 0;
        if(randomIndex == i || matches.at(i).derby){
            continue;
        }else{
            std::swap(matches.at(i),matches.at(randomIndex));
        }
    }
}
// Print Weekend games to std::cout
void Util::displayFixtures(){
    for(int i = 0; i < weekendGames.size(); i++){
        std::cout<<"|------------ Week #"<<i+1<<" ------------\n\n";
        for(int j = 0; j < 2; j++){
            std::cout<<"| ";
            std::cout<<weekendGames.at(i).matches[j].home.name;
            std::cout<<" vs ";
            std::cout<<weekendGames.at(i).matches[j].away.name;
            std::cout<<"\n| Stadium: ";
            std::cout<<weekendGames.at(i).matches[j].home.stadium<<std::endl;
            std::cout<<"\n";
        }
        
        std::cout<<"|--------------------------------\n\n";
    }
}
// Check if teams have played each other before 
bool Util::havePlayedBefore(Team a,Team b){
    // Go through all matches
    for(int i = 0; i < matches.size(); i++){
        Match currentMatch = matches.at(i);
        // check if a b or b a exists 
        if(
            (currentMatch.home.name == a.name && currentMatch.away.name == b.name)
            ||
            (currentMatch.home.name == b.name && currentMatch.away.name == a.name)
        ){
            return true;
        }
    }
    return false;
}
 // Ensures second legs matches come after all the first legs have been played (Bubble Sort)
void Util::sortMatches(){
    for(int i = 0; i < matches.size(); i++){
        for(int j = 0; j < matches.size() - i - 1; j++){
            if(matches.at(j).leg > matches.at(j+1).leg){
                std::swap(matches.at(j),matches.at(j+1));
            }
        }
    }
}

int Util::getFixturesCount(){
    return weekendGames.size();
}

int Util::getTeamCount(){
    return teams.size();
}