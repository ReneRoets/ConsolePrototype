#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int selection = 0;
void menu();
void showlog();
void makelog();

int main(){
    cout << endl;
    menu();
}

class Log {
public:
    string name;
    int timestart, timeend, total;
};

void menu()
{
    selection = 0;
    cout << " Uren Registratie - \n";
    cout << " 1. Register Log\n";
    cout << " 2. show Log\n";
    cout << " 3. Exit\n";
    cout << "\t";
    cin >> selection;

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

    cout << "Uren registratie ";
    cout << "\nName ";
    cin >> newLog.name;
    cout << "\n start tijd ";
    cin >> newLog.timestart;
    cout << "\n eind tijd ";
    cin >> newLog.timeend;
    cout << "\n totaal ";
    cin >> newLog.total;


    cout << "\n log gelogged";

    std::ofstream log;

    log.open("newlog.txt");

    log << newLog.name << endl;
    log << newLog.timestart << endl;
    log << newLog.timeend << endl;
    log << newLog.total << endl;
    log.close();
    menu();

}

void showlog() {
    ifstream inFile;
    inFile.open("newlog.txt");

    if (inFile.fail()) {
        cerr << "error" << endl;
        exit(1);
    }
    
    if (inFile.is_open())
    std::cout << inFile.rdbuf();
    std::cout << "\n";

    menu();

}