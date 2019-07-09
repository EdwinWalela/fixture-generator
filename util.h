//@ TODO: File opening error checking

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

struct Team
{
    std::string name;
    std::string town;
    std::string stadium;
};


class Util{
    private:
    std::ifstream inputStream; 
    std::ofstream outputStream;

    std::vector<Team> teams; // List of all teams;  

    public:
    void readFile(std::string);
    void writeFile(std::string);
    void printTeams();
};

// Read input from file
void Util::readFile(std::string _dir){
    // Open target file
    inputStream.open(_dir,std::ios::in);

    /* --- Manipulate data  --- */
    // Ignore first line of file (Contains Headers) 
    std::string str;
    // getline(inputStream)
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

void Util::printTeams(){
     std::cout<<teams.at(1).town<<",";
    for(int i = 1; i < teams.size(); i++){
        std::cout<<teams.at(i).name<<",";
        std::cout<<teams.at(i).town<<",";
        std::cout<<teams.at(i).stadium<<std::endl;
    }
}