//@ TODO: File opening error checking

#include <fstream>
#include <string>


class Util{
    private:
    std::ifstream inputStream; 
    std::ofstream outputStream;

    public:
    void readFile(std::string);
    void writeFile(std::string);
};

// Read input from file
void Util::readFile(std::string _dir){
    // Open target file
    inputStream.open(_dir,std::ios::in);

    /* --- Manipulate data  --- */

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