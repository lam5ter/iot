Internet of Things (IOT)

by Nathan Lam (10/09/2017)

=======================================================================

Operating Instructions:

$ ./run [FLAGS]

Optional Flags:
		-p - Prints output to STDIN
		-l - Logs output to tmp/log.txt
        -h or -? - Prints help file

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
    help.txt - Help file with operation instructions

ext:

include:
    weather.h - Header file for src/weather.cpp
    io_control.h - Header file for src/io_control.cpp

src:
    main - Main program file
    weather - Utilised shell script (bin/weather.sh) to determine
                  current weather.

tmp:
    log.txt - History log of the weather

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

10/09/2017 - 22:42
    - Fixed bug where RGB LED was not reset before next update
    - Added printing/debug mode

11/09/2017 - 08:47
    - Fixed bug where LED was red when sunny
    - Added tmp/log.txt
    - Added logging flag

13/09/2017 - 00:20
    - Added include folder and updated Makefile
    - Created io_control
    - Added timestamping in log
    - Added debounce switch

16/09/2017 - 17:51
    - Added sleep time for LED to turn off during (2300 - 0600)
    - Create a help file and a corresponding flag

