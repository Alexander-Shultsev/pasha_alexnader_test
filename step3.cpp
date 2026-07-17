#include <iostream>
#include <windows.h>
#include <cstdint>

void testValue(int32_t f) {
    f -= 30;
}

void testReference(int32_t& f) {
    f -= 30;
}

void testAltitude(int32_t f) {
    f += 25;
}

void testRefAlti(int32_t& f) {
    f += 25;
}

int function() {
    using namespace std;

    int32_t fuel = 100;
    int32_t altitude = 60;

    testValue(fuel);
    cout << "fuel - " << fuel << endl;

    testReference(fuel);
    cout << "fuel - " << fuel << endl;

    testAltitude(altitude);
    cout << "altitude - " << altitude << endl;

    testRefAlti(altitude);
    cout << "altitude - " << altitude << endl;


    return 0;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    function();
}
