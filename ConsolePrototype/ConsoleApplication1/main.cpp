#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int selection = 0;
void menu();
void showlog();
void makelog();
void json();

int main(){
    std::cout << std::endl;
    menu();
}

class Log {
public:
    std::string name, timestart, timeend, total;
};

void menu()
{
    selection = 0;
    std::cout << " Uren Registratie - \n" << std::endl;
    std::cout << " 1. Register Log\n" << std::endl;
    std::cout << " 2. show Log\n" << std::endl;
    std::cout << " 3. Exit\n" << std::endl;
    std::cout << "\t";
    std::cin >> selection;

    if (selection == 1)
    {
        makelog();
    }
    else if (selection == 2)
    {
        showlog();
    }
    else if (selection == 3)
    {
        exit(0);
    }
}

void makelog() {

    Log newLog;

    std::cout << "Uren registratie " << std::endl;
    std::cout << "\n voer de naam in van de dag" << std::endl;
    std::cin >> newLog.name;
    std::cout << "\n start tijd " << std::endl;
    std::cin >> newLog.timestart;
    std::cout << "\n eind tijd " << std::endl;
    std::cin >> newLog.timeend;
    std::cout << "\n totaal " << std::endl;
    std::cin >> newLog.total;


    std::cout << "\n log gelogged" << std::endl;

    std::ofstream log;

    log.open("newlog.txt");

    log << newLog.name << std::endl;
    log << newLog.timestart << std::endl;
    log << newLog.timeend << std::endl;
    log << newLog.total << std::endl;
    log.close();
    menu();

}

void showlog() {
    std::ifstream inFile;
    inFile.open("newlog.txt");

    if (inFile.fail()) {
        std::cerr << "error" << std::endl;
        exit(1);
    }
    
    if (inFile.is_open())
    std::cout << inFile.rdbuf();
    std::cout << "\n";

    menu();
}
