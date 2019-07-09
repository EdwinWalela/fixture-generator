//@ TODO: File opening error checking

#include <fstream>
#include <string>
#include <vector>
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
    int leg;
};

struct Weekend
{
    Match matches[2];
};

class Util{
    private:
    std::ifstream inputStream; 
    std::ofstream outputStream;
    std::vector<Team> teams; // List of all teams
    std::vector<Match> matches; // List of all mathces (90)
    std::vector<Weekend> weekendGames; // List of all fixtures (45)

    public:
    // Methods
    void readFile(std::string);
    void writeFile(std::string);
    void printTeams();
    void createMatches();
    void displayMatches();
    void createWeekendGames();
    void displayFixtures();
    void shuffleMatches();

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
    // Open target file
    outputStream.open(_dir,std::ios::app);

    /* --- Manipulate data --- */

    outputStream.close();
}

// Print list of teams on console
void Util::printTeams(){
    for(int i = 0; i < teams.size(); i++){
        std::cout<<teams.at(i).name<<",";
        std::cout<<teams.at(i).town<<",";
        std::cout<<teams.at(i).stadium<<std::endl;
    }
}

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
                derby.leg = 1;
            }else{
                Match match;
                match.home = currentTeam;
                match.away = teams.at(j);
                match.leg = 1;
                matches.push_back(match);
            }
        }
        // Add derby match after the current team has already played with all other teams
        matches.push_back(derby);
    }
}

void Util::displayMatches(){
    for(int i = 0; i < matches.size(); i++){
        std::cout<<"\n--------------match #"<<i+1<<"--------------\n";
        std::cout<<matches.at(i).home.name<<" vs "<<matches.at(i).away.name;
        std::cout<<"\n---------------------------------------\n";
    }
}

void Util::createWeekendGames(){
    shuffleMatches();
    for(int i = 0; i < matches.size()-1; i+=2){
        Weekend weekend;
        weekend.matches[0] = matches.at(i);
        weekend.matches[1] = matches.at(i+1);
        weekendGames.push_back(weekend);
    }
}

void Util::shuffleMatches(){
    srand(time(NULL)); // Initialize random seed
    for(int i = matches.size()-1; i > 0; i--){
        // Generate random number between 0 and i
        int randomIndex = rand() % i + 0;
        if(randomIndex == i){
            continue;
        }else{
            std::swap(matches.at(i),matches.at(randomIndex));
        }
    }
}

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



