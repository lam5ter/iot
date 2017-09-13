// Nathan Lam 10/09/2017
// IOT Project

#ifndef WEATHER_H
#define WEATHER_H

void string_lower(char *s);
void chomp(char *s);
void det_weather(char *s, char *dest);
void weather_today(char *s);
int det_colour(char *weather);

const char * const TYPES[] = {
    "rain",
    "shower",
    "windy",
    "cloudy",
    "foggy",
    "sunny",
    "clear"
};

// BLUE 1, RED 3, GREEN 2
const int COLOURS[] = {
    1,
    1,
    3,
    3,
    3,
    2,
    2
};

#endif

