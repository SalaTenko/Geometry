all: bin/circle

bin/circle: build/circle.o build/main.o
	gcc -Wall -Werror build/circle.o build/main.o -o bin/circle -lm

build/circle.o: src/circle.h src/circle.c
	gcc -I src -Wall -Werror -c src/circle.c -o build/circle.o -lm

build/main.o: src/circle.h src/main.c
	gcc -I src -Wall -Werror -c src/main.c -o build/main.o -lm

clear:
	rm -rf build/*.o bin/circle
