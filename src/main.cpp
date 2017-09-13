#include <iostream>
#include <ctime>

// Header files
#include "weather.h"
#include "io_control.h"

using namespace std;

int main(int argc, char *argv[]) {

    flags *f = update_flags(argc, argv);

    init_io();

    char weather[20];
    bool pressed = false;

    // While the exit button has not been pressed
    while (!pressed) {
        // Reset RGB LED
        reset_rgb();

        // Check current weather
        weather_today(weather);
        // Check for the corresponding colour for the weather
        int colour = det_colour(weather);
        
        record_data(f, weather, colour);

        // Update RGB LED colour
        update_rgb(colour);

        // Wait 1 hour before next check
        pressed = is_exit();
    }

    reset_gpio();

    delete f;

    return 0;

}

