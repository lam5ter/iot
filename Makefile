# Define required macros here

OBJS = bin/main.o bin/weather.o bin/io_control.o
CFLAGS = -Wall -Werror -I include
CC = g++
LIBS = -lwiringPi

all: ${OBJS}
	${CC} ${CFLAGS} -o bin/$@ ${OBJS} ${LIBS}


bin/main.o:
	${CC} ${CFLAGS} -c -o $@ src/main.cpp

bin/weather.o:
	${CC} ${CFLAGS} -c -o $@ src/weather.cpp 

bin/io_control.o:
	${CC} ${CFLAGS} -c -o $@ src/io_control.cpp

clean:
	rm -f bin/*.o core bin/all tmp/log.txt
