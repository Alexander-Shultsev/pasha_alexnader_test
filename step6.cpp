#include <iostream>
#include <cstdint>
#include <windows.h>
#include <cstring>
#include <windows.h>
#include <format>
#include <iterator>

// Структуры

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    using namespace std;

    enum class CommandType {
        TAKEOFF,  // В памяти это просто число 0
        WAYPOINT, // В памяти это число 1
        LAND      // В памяти это число 2
    };

    struct Point2D {
        int32_t latitude;  // Широта
        int32_t longitude; // Долгота
    };
    
    struct DroneCommand {
        CommandType type;  // Наш enum из примера выше
        int32_t altitude;  // Высота для этой команды
        Point2D target;    // Структура внутри структуры (координаты точки)
    };

    DroneCommand cmd;
    cmd.type = CommandType::WAYPOINT;
    cmd.altitude = 100;
    cmd.target.latitude = 557522;
    cmd.target.longitude = 376156;







    enum class FlightState {
        ON_GROUND,
        FLYING,
        EMERGENCY
    };

    struct Telemetry {
        FlightState state;
        int32_t altitude;
        uint32_t battery;
    };


    Telemetry flightLogs[3];

    flightLogs[0].state = FlightState::ON_GROUND;
    flightLogs[0].altitude = 0;
    flightLogs[0].battery = 100;

    flightLogs[1].state = FlightState::FLYING;
    flightLogs[1].altitude = 50;
    flightLogs[1].battery = 85;

    flightLogs[2].state = FlightState::EMERGENCY;
    flightLogs[2].altitude = 15;
    flightLogs[2].battery = 10;

    char status[256];

    for (int i = 0; i < size(flightLogs); i++) {

        switch (flightLogs[i].state) {
            case FlightState::ON_GROUND:
                snprintf(status, sizeof(status), "На земле");
                break;
            case FlightState::FLYING:
                snprintf(status, sizeof(status), "В полёте");
                break;
            case FlightState::EMERGENCY:
                snprintf(status, sizeof(status), "Авария");
                break;
            default:
                cout << "Некорректный статус";

        }
        cout << format("Данные логов {} дрона: Статус - {}, Высота - {}, Батарея - {}\n\n", i + 1, status, flightLogs[i].altitude, flightLogs[i].battery);
    }

    return 0;
}