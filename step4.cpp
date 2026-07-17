#include <iostream>
#include <cstdint>
#include <cstdlib>  // Библиотека, в которой живут malloc и free
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    using namespace std;

    int32_t pointNum = 0;
    cout << "Введите количество маршрутных точек для миссии: ";
    cin >> pointNum;

    if (pointNum <= 0) {
        cout << "Ошибка: количество точек должно быть больше 0!" << endl;
        return 1;
    }

    // Мы просим память под (pointNum * 4 байта) и приводим результат к указателю (int32_t*)
    int32_t* altitudes = (int32_t*)malloc(pointNum * sizeof(int32_t));
    int32_t* longtitude = (int32_t*)malloc(pointNum * sizeof(int32_t));

    // 2. ПРОВЕРКА ОБЕИХ ОБЛАСТЕЙ ПАМЯТИ (Защита от сбоя)
    if (altitudes == NULL || longtitudes == NULL) {
        cout << "Критическая ошибка: не удалось выделить память под миссию!" << endl;
        // Если первый успел выделиться, а второй нет - нужно очистить первый перед выходом!
        if (altitudes != NULL) free(altitudes);
        if (longtitudes != NULL) free(longtitudes);
        return -1;
    }

    // 2. РАБОТА С МАССИВОМ (заполняем высоты с шагом 50 метров)
    for (int i = 0; i < pointNum; i++) {
        altitudes[i] = (i + 1) * 50; // Точка 1: 50м, Точка 2: 100м и т.д.
    }

    // Выводим сгенерированную миссию на экран
    cout << "\n--- Сгенерированный профиль высот ---" << endl;
    for (int i = 0; i < pointNum; i++) {
        cout << "Точка #" << (i + 1) << altitudes[i] << << endl;
    }

    // 3. ОСВОБОЖДЕНИЕ ПАМЯТИ (Обязательно!)
    free(altitudes);
    altitudes = NULL; // Хороший тон: обнулить указатель после освобождения

    cout << "\nПамять успешно очищена. Миссия завершена." << endl;
    return 0;
}