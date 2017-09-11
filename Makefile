# Define required macros here

OBJS = bin/main.o bin/weather.o
CFLAGS = -Wall -Werror -I include
CC = g++
LIBS = -lwiringPi

all: ${OBJS}
	${CC} ${CFLAGS} -o bin/$@ ${OBJS} ${LIBS}


bin/main.o:
	${CC} ${CFLAGS} -c -o bin/main.o src/main.cpp

bin/weather.o:
	${CC} ${CFLAGS} -c -o bin/weather.o src/weather.cpp 

clean:
	rm -f bin/*.o core bin/all
