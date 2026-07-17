#include <iostream>
#include <cstdint>
#include <windows.h>

int trainProgram() {
    using namespace std;
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int32_t longitude = 557522;
    int32_t latitude = 376156;
    int32_t altitude = 100;

    cout << "Долгота: " << longitude << std::endl;
    cout << "Широта: " << latitude << std::endl;
    cout << "Высота: " << altitude << std::endl;
    
    cin >> altitude;
    cout << "Высота: " << altitude << std::endl;
    
    return 0;
}

int main() {
    using namespace std;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. Объявление переменных (типы из вашего полетного контроллера)
    uint32_t commandNum = 15;        // Количество команд (только > 0)
    int32_t altitude = -50;          // Высота (может быть отрицательной относительно точки старта)
    float delayTime = 1.5f;          // Число с плавающей точкой (секунды задержки)
    bool isKillSwitchActive = false; // Логический тип: true (1) или false (0)
    char stopSymbol = '#';           // Одиночный символ в одинарных кавычках

    // 2. Вывод данных в консоль с помощью std::cout
    std::cout << "--- Статус контроллера ---" << std::endl;
    std::cout << "Количество команд: " << commandNum << std::endl;
    std::cout << "Текущая высота: " << altitude << " метров" << std::endl;
    std::cout << "Символ окончания миссии: " << stopSymbol << std::endl;

    // 3. Изменение значения переменной
    altitude = 100;
    std::cout << "Новая высота после взлета: " << altitude << " метров" << std::endl;

    // 4. Простой ввод данных от пользователя (std::cin)
    std::cout << "Введите новое количество команд: ";
    std::cin >> commandNum;
    std::cout << "Введите статус кил свитч(1 - true, 0 - false): ";
    std::cin >> isKillSwitchActive;
    std::cout << "Введите новый стоп символ: ";
    std::cin >> stopSymbol;
    std::cout << "Система приняла " << commandNum << " команд(ы)." << std::endl;
    std::cout << "Система приняла " << isKillSwitchActive << " статус." << std::endl;
    std::cout << "Система приняла " << stopSymbol << " символ." << std::endl;

    trainProgram();

    return 0; // 0 означает, что программа завершилась без ошибок
}