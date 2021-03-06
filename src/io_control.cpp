#include <iostream>
#include <fstream>
#include <cstring>
#include <wiringPi.h>
#include <ctime>

#include "io_control.h"
#include "weather.h"

using namespace std;

flags *update_flags(int num, char *args[]) {

    flags *f = new struct _flags;
    f->print = f->log = false;
    
    for (int i = 1; i < num; i++) {
        if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "-?") == 0) {
            // Print help file
            ifstream h;
            h.open("../doc/help.txt");
            if (h.is_open())
                cout << h.rdbuf();
            h.close();
            delete f;
            exit(0);
        } else if (strcmp(args[i], "-p") == 0)
            f->print = true;
        else if (strcmp(args[i], "-l") == 0)
            f->log = true;
        else {
            // Print error message for invalid flag.
            cout << "Invalid flag. Use ./run -h for usage." << endl;
            delete f;
            exit(0);
        }
    }

    return f;

}

bool is_log(flags *f) {

    return f->log;

}


void record_data(flags *f, char *weather, int colour) {

    time_t cur_time;
    time(&cur_time);
    char *log_time = ctime(&cur_time);
    chomp(log_time);
    if (weather == NULL) {
        cout << "io_control.cpp: record: No weather data" << endl;
        exit(1);
    } else if (colour == -1) {
        cout << "io_control.cpp: record: Weather not in bank" << endl;
        exit(1);
    } else {
        if (f->log == true) {
		    ofstream fp;
    		fp.open("../tmp/log.txt", ios::app);
            fp << log_time << '\t' << weather << ", " << colour << endl;
		    fp.close();
        }
        if (f->print == true)
            cout << log_time << '\t' << weather << ", " << colour << endl;
    }

}


void init_io() {

    //Initialisation of RP GPIO pins
    wiringPiSetup();
    pinMode(0, INPUT);  // GPIO 0 = Emergency stop button
    for (int i = 1; i <= 3; i++)
        pinMode(i, OUTPUT);
    reset_rgb();

}

void update_rgb(int colour) {

    time_t cur_time = time(NULL);
    struct tm *t = localtime(&cur_time);
    
    if (t->tm_hour <= 6 || t->tm_hour >= 23) return;

    digitalWrite(colour, LOW);

}

bool is_exit() {

    for (int i = 0; i < 14400; i++) {
        // Poll exit button
        if (digitalRead(0) == HIGH) {
            // Debouce button
			delay(3000);
			if (digitalRead(0) == HIGH)
            	return true;
        }
        delay(250);
    }

	return false;

}


void reset_rgb() {

    // GPIO 1-3 = RGB LED;
    for (int i = 1; i <= 3; i++)
        digitalWrite(i, HIGH);

}

void reset_gpio() {

    // Return GPIO pins to initial state
    for (int i = 1; i <= 3; i++) {
        pinMode(i, INPUT);
    }

}

