#include <iostream>
#include <windows.h>
#include <cstdint>

void testValue(int32_t f) {
    f -= 30;
}

void testReference(int32_t& f) {
    f -= 30;
}

void altitudeTest(int32_t a) {
    a += 25;
}

void altitudeReference(int32_t& a) {
    a += 25;
}

int function() {
    using namespace std;

    int32_t fuel = 100;
    int32_t altitude = 20;

    testValue(fuel);
    cout << "fuel - " << fuel << endl;

    testReference(fuel);
    cout << "fuel - " << fuel << endl;

    altitudeTest (altitude);
    cout << "Высота - " << altitude << endl;
    altitudeReference (altitude);
    cout << "Высота - " << altitude << endl;

    return 0;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    function();
}
