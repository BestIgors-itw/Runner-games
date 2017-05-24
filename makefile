CFLAGS = -Wall -Werror -MP -MMD
SOURCES = src/main.cpp src/Entity.cpp src/Player.cpp src/Object.cpp
.PHONY: clean all ScrollShooter test

all :
	make bin/ScrollShooter

bin/ScrollShooter : build/main.o build/Entity.o  build/Player.o build/Object.o
	gcc build/main.o build/Entity.o build/Player.o build/Object.o -o bin/ScrollShooter $(CFLAGS)

build/main.o : src/main.cpp src/Entity.h src/Player.h src/Object.h
	gcc -c src/main.cpp -o build/main.o $(CFLAGS)

build/Player.o : src/Player.cpp src/Player.h src/Entity.h
	gcc -c src/Player.cpp -o build/Player.o $(CFLAGS)

build/Object.o : src/Object.c src/Object.h src/Entity.h
	gcc -c src/Object.cpp -o build/Object.o $(CFLAGS)

build/Entity.o : src/Entity.cpp src/Entity.h
	gcc -c src/Entity.cpp -o build/Entity.o $(CFLAGS)

clean :
	@rm -rf build/*.d build/test/*.d 
	@rm -rf build/*.o build/test/*.o
	@rm bin/deposit-calc bin/deposit-calc-test
	@echo "All files have been cleaned."
	
-include build/*.d
