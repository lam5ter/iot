#include <iostream>
#include <wiringPi.h>


using namespace std;



    // GPIO 1-3 = RGB LED;
    for (int i = 1; i <= 3; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }

    

}
