OPTS = -Wall -g
LIBS = -L/usr/lib -L/usr/X11R6/lib -lX11 -lGL -lGLU -lglui -lglut -ljpeg

main: main.cc main.h lazer.h ship.h asteroid.h
	g++ ${OPTS} -o main main.cc ${LIBS}

clean:
	rm *.*~
	rm main
