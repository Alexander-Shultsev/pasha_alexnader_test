#include <iostream>
#include <windows.h>
#include <cstdint>

// Функции

float sum(uint8_t one, uint8_t two) {
    return one + two * 8 / 5;
}

void testValue(int32_t f) {
    f -= 30;
}

void testReference(int32_t& f) {
    f -= 30;
}

int function() {
    using namespace std;

    int32_t fuel = 100;

    testValue(fuel);
    cout << "fuel - " << fuel << endl;

    testReference(fuel);
    cout << "fuel - " << fuel << endl;

    float newValue = sum(4, 7);
    cout << "Новое значение " << newValue << endl;

    return 0;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    function();
}
