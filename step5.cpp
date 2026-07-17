#include <iostream>
#include <cstdint>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <format>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    using namespace std;
    
    cout << format("Failed to receive an arm request from Autopilot Connector. Trying again in {}s\n", 12);

    char serverResponse[] = "INFO:OK&ID=2026&$FlightMission Takeoff_50&Waypoint_100#";

    char altitude[] = "Высота равна 50";
    char longtitude[] = "долгота равна 20";
    char latitude[] = "широта равна 50";
    cout << altitude << endl;
    cout << longtitude << endl;
    cout << latitude << endl;
    char* takeoff = strstr(serverResponse, "Takeoff");
    cout << "Значение, начиная с указателя: " << takeoff << endl;
    char* sila = takeoff + strlen("Takeoff_50&");
    cout << "Значение, со смещением: " << sila << endl;



    char* id = strstr(serverResponse, "ID=");
    char* flightMission = strstr(serverResponse, "$FlightMission ");


    

    if (id == NULL) { 
        cout << "ID не найден";
    } else {
        cout << "Значение, начиная с указателя: " << id << endl << endl;
    }

    if (flightMission == NULL) {
        cout << "Миссия в сообщении не обнаружена!";
    } else {
        cout << "Значение, начиная с указателя: " << flightMission << endl << endl;
        char* commandsOnly = flightMission + strlen("$FlightMission ");
        cout << "Только команды " << commandsOnly;

    }

    return 0;
}