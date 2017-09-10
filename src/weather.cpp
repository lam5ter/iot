#include <iostream>
#include <cstring>
#include "weather.h"

using namespace std;

void string_lower(char *s) {

    if (s == NULL) return;

    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }

}

void chomp(char *s) {

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\n') {
			s[i] = '\0';
			break;
		}
	}

}

void det_weather(char *s, char *dest) {

    int max = sizeof(COLOURS) / sizeof(int), i;
    char *weather;
    //cout << "Number of weather conditions: " << max << endl;

    for (i = 0; i < max; i++) {
        weather = strstr(s, TYPES[i]);
        if (weather != NULL) break;
    }

    if (weather == NULL) {
        cout << "weather.cpp: Could not determine weather" << endl;
        exit(1);
    }

    strcpy(dest, TYPES[i]);

}


void weather_today(char *s) {

    // Check weather online
    FILE *fp = popen("./weather.sh", "r");
    if (fp == NULL) {
        cout << "main.cpp: Failed to execute popen" << endl;
        exit(1);
    }
    char buff[100];
    if (fgets(buff, sizeof(buff), fp) == NULL) {
        cout << "main.cpp: Failed to execute ./weather.sh" << endl;
        exit(1);
    }
    pclose(fp);

    string_lower(buff);
	chomp(buff);
    // cout << buff << endl;
    char weather[20];
    det_weather(buff, weather);

    strcpy(s, weather);

}

int det_colour(char *weather) {

    // Iterator
    int i, max = sizeof(COLOURS) / sizeof(int);

    if (weather == NULL) {
        cout << "weather.cpp: det_colour: Weather is NULL" << endl;
        exit(1);
    }

    for (i = 0; i < max; i++) {
        if (strcmp(weather, TYPES[i]) == 0) break;
    }

    if (i < max) return COLOURS[i];
    else return -1;

}
