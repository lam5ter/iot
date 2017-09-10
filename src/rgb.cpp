#include <iostream>
#include <wiringPi.h>
#include <fstream>
#include <stdio.h>

// Header files
#include "weather.h"

using namespace std;

int main() {

    //Initialisation of RP GPIO pins
    wiringPiSetup();
    pinMode(0, INPUT);  // GPIO 0 = Emergency stop button

    // GPIO 1-3 = RGB LED;
    for (int i = 1; i <= 3; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }

    
    char weather[20];
    weather_today(weather);
    if (weather == NULL) {
        cout << "Line 27: No weather data" << endl;
        exit(1);
    } else {
        cout << "Today is " << weather << endl;
    }

    // Flash RGB LED
    /*
    while (1) {
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        delay(500);
        if (digitalRead(0) == HIGH) break;
        digitalWrite(2, LOW);
        digitalWrite(1, HIGH);
        delay(500);
        if (digitalRead(0) == HIGH) break;
        digitalWrite(3, LOW);
        digitalWrite(2, HIGH);
        delay(500);
        if (digitalRead(0) == HIGH) break;
    }
    */
    while (1) {
        int colour = det_colour(weather);
        if (colour == -1) {
            cout << "main.cpp: Weather not in bank" << endl;
            exit(0);
        }
        //digitalWrite(colour, LOW);
        digitalWrite(2, LOW);
        if (digitalRead(0) == HIGH) break;
        delay(250);
    }

    // Return GPIO pins to initial state
    for (int i = 1; i <= 3; i++) {
        pinMode(i, INPUT);
    }

    return 0;

}
