#include <iostream>
#include <cstdint>
#include <windows.h>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <format>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    using namespace std;
    
    cout << format("Failed to receive an arm request from Autopilot Connector. Trying again in {}s\n", 12);

    char serverResponse[] = "INFO:OK&ID=2026&$FlightMission Takeoff_50&Waypoint_100#";

    char altitude[] = "Высота равна 150 метрам";
    char longtitude[] = "Долгота равна 30 метрам";
    char latitude[] = "Широта равна 20 метров";

    cout << altitude << endl;
    cout << longtitude << endl;
    cout << latitude << endl;

    char* id = strstr(serverResponse, "ID=");
    char* flightMission = strstr(serverResponse, "$FlightMission ");
    char* takeoff = strstr(serverResponse, "Takeoff_");
    

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
        cout << "Только команды " << commandsOnly << endl;

    }

    if (takeoff == NULL) { 
        cout << "Данные взлета не найдены";
    } else {
        cout << "Данные взлета: " << takeoff << endl << endl;
        char* pasha = takeoff + strlen("$Takeoff_50");
        cout << "Данные взлета без взлета: " << pasha << endl << endl;
    }

    return 0;
}