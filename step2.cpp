#include <iostream>
#include <cstdint>
#include <windows.h>
#include <cctype>
#include <algorithm>

// Условия и циклы

int ifWhile() {
    using namespace std;

    bool isArmed = false;     // Состояние: отключены моторы (false) или крутятся (true)
    int32_t altitude = 0;     // Высота
    char command;             // Текущая команда от оператора

    cout << "--- Симулятор управления полетом запущен ---" << endl;

    // Бесконечный цикл опроса команд (как в реальном контроллере)
    while (true) {
        cout << "\n[Статус: " << (isArmed ? "ARMED (Моторы работают)" : "DISARMED (На земле)") 
                  << " | Высота: " << altitude << "м]" << endl;
        
        cout << "Введите команду (A - Arm, T - Takeoff, L - Land, Q - Выход, U - Взлёт на 25 местров): ";
        cin >> command;

        // Приведение к нижнему регистру
        command = tolower(static_cast<unsigned char>(command));

        // Обработка команд через switch/case
        switch (command) {
            case 'a': // Поддержка маленькой буквы
                if (!isArmed)
                {
                    isArmed = true;
                    cout << ">> Внимание! Моторы запущены (ARMED)." << endl;
                }
                else
                {
                    cout << ">> Ошибка: Моторы уже запущены!" << endl;
                }
                break;

            case 't':
                if (isArmed && altitude == 0) {
                    altitude = 50;
                    cout << ">> Взлет! Дрон на высоте 50 метров." << endl;
                } else if (!isArmed) {
                    cout << ">> Ошибка взлета: Сначала запустите моторы (A)!" << endl;
                } else {
                    cout << ">> Дрон уже в воздухе!" << endl;
                }
                break;

            // 1. Если моторы запущены
            // 2. Если высота больше 0
            // 3. Взлёт + 25 метров
            // Если моторы не запущены - предупреждение
            // Если высота равна 0 - дрон не взлетел

            case 'l':
                if (altitude > 0) {
                    altitude = 0;
                    cout << ">> Посадка завершена. Высота 0м." << endl;
                } else {
                    cout << ">> Дрон уже на земле!" << endl;
                }
                break;

            case 'q':
                cout << ">> Отключение питания. Завершение работы." << endl;
                return 0; // Единственный способ выйти из while(true)

            default:  // Если ввели любой другой символ (аналог блока default в вашем коде)
                cout << ">> Неизвестная команда '" << command << "'! Будьте внимательны." << endl;
                break;
        }
    }

    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ifWhile();
}
