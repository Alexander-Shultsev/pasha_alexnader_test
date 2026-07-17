#include <iostream>
#include <cstdint>
#include <windows.h>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <format>

// Строки

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    using namespace std;
    
    cout << format("Failed to receive an arm request from Autopilot Connector. Trying again in {}s\n", 12);

    char serverResponse[] = "INFO:OK&ID=2026&$FlightMission Takeoff_50&Waypoint_100#";

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