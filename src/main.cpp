#include <iostream>
#include <wiringPi.h>
#include <fstream>
#include <cstring>

// Header files
#include "weather.h"

using namespace std;

int main(int argc, char *argv[]) {

    bool print = false;
    if (argc > 1 && strcmp(argv[1], "-p") == 0)
        print = true;
    //Initialisation of RP GPIO pins
    wiringPiSetup();
    pinMode(0, INPUT);  // GPIO 0 = Emergency stop button

    // GPIO 1-3 = RGB LED;
    for (int i = 1; i <= 3; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }

    
    char weather[20];
    bool pressed = false;

    // While the exit button has not been pressed
    while (!pressed) {
        // Reset RGB LED
        for (int i = 1; i <= 3; i++)
            digitalWrite(i, HIGH);

        // Check current weather
        weather_today(weather);
        if (weather == NULL) {
            cout << "Line 27: No weather data" << endl;
            exit(1);
        } else if (print == true) {
            cout << "Today is " << weather << endl;
        }

        // Check for the corresponding colour for the weather
        int colour = det_colour(weather);

        if (colour == -1) {
            cout << "main.cpp: Weather not in bank" << endl;
            exit(0);
        }

        // Update RGB LED colour
        digitalWrite(colour, LOW);

        // Wait 1 hour before next check
        for (int i = 0; i < 14400; i++) {
            // Poll exit button
            if (digitalRead(0) == HIGH) {
                pressed = true;
                break;
            }
            delay(250);
        }
    }

    // Return GPIO pins to initial state
    for (int i = 1; i <= 3; i++) {
        pinMode(i, INPUT);
    }

    return 0;

}

