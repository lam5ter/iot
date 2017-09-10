Internet of Things (IOT)

by Nathan Lam (10/09/2017)

=======================================================================

Operating Instructions:

$ ./run

Push button (active HIGH) connected to GPIO 0 to stop program

=======================================================================

File Manifest:

Makefile - Make instructions to build binary

run - Executable

bin:
    all - Executable file
    weather.sh - Shell script to get current weather information
    *.o - Object files to build the final binary

doc:

ext:

src:
    main - Main program file
    weather - Utilised shell script (bin/weather.sh) to determine
                  current weather.


=======================================================================

Known bugs:
 - If the executable is run outside of the bin/ directory, the script
   weather.sh will not be run

 - If the weather summary does not match one of the key words, the
   program will have a segmentation fault

=======================================================================

Changelog:

10/09/2017 - 15:59
    - Created main
    - Created weather
    - Retrieves informations from Australian Bureau of Meterology
      website on current weather.
    - Flashes RGB LED using GPIO 0-3

10/09/2017 - 16:33
    - Identifies weather from a bank of weather types

10/09/2017 - 17:07
    - Changes RGB LED to corresponding colour

