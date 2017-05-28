CFLAGS = -Wall -Werror
SOURCES = src/main.cpp src/Entity.cpp src/Player.cpp src/Background.cpp src/Hedges.cpp src/Direction.cpp src/Effects.cpp src/Enemies.cpp src/Interface.cpp
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = build/main.o build/Background.o build/Bullets.o build/Direction.o build/Effects.o build/Enemies_Cars.o build/Entity.o build/Hedges.o build/Interface.o build/Player.o build/Race.o build/Scroll_Shooter.o build/Shooter.o build/Shooter_enemies_cars.o

.PHONY: clean all Runner-games test

all :
	make bin/Runner-games

bin/Runner-games : $(OBJECTS)
	g++ build/main.o build/Background.o build/Bullets.o build/Direction.o build/Effects.o build/Enemies_Cars.o build/Entity.o build/Hedges.o build/Interface.o build/Player.o build/Race.o build/Scroll_Shooter.o build/Shooter.o build/Shooter_enemies_cars.o -o bin/Runner-games $(CFLAGS) $(LDFLAGS)

build/main.o : src/main.cpp src/Background.cpp src/Bullets.cpp src/Direction.cpp src/Effects.cpp src/Enemies_Cars.cpp src/Entity.cpp src/Hedges.cpp src/Interface.cpp src/Player.cpp src/Race.cpp src/Scroll_Shooter.cpp src/Shooter.cpp src/Shooter_enemies_cars.cpp
	g++ -c src/main.cpp -o build/main.o $(CFLAGS) $(LDFLAGS)

build/Entity.o : src/Entity.cpp src/Entity.h
	g++ -c src/Entity.cpp -o build/Entity.o $(CFLAGS) $(LDFLAGS)

build/Player.o : src/Player.cpp src/Player.h src/Entity.h
	g++ -c src/Player.cpp -o build/Player.o $(CFLAGS) $(LDFLAGS)

build/Background.o : src/Background.cpp src/Background.h src/Entity.h
	g++ -c src/Background.cpp -o build/Background.o $(CFLAGS) $(LDFLAGS)

build/Bullets.o : src/Bullets.cpp src/Bullets.h src/Entity.h
	g++ -c src/Bullets.cpp -o build/Bullets.o $(CFLAGS) $(LDFLAGS)

build/Direction.o : src/Direction.cpp src/Direction.h src/Entity.h
	g++ -c src/Direction.cpp -o build/Direction.o $(CFLAGS) $(LDFLAGS)

build/Effects.o : src/Effects.cpp src/Effects.h src/Entity.h
	g++ -c src/Effects.cpp -o build/Effects.o $(CFLAGS) $(LDFLAGS)

build/Enemies_Cars.o : src/Enemies_Cars.cpp src/Enemies_Cars.h src/Entity.h
	g++ -c src/Enemies_Cars.cpp -o build/Enemies_Cars.o $(CFLAGS) $(LDFLAGS)

build/Hedges.o : src/Hedges.cpp src/Hedges.h src/Entity.h
	g++ -c src/Hedges.cpp -o build/Hedges.o $(CFLAGS) $(LDFLAGS)

build/Interface.o : src/Interface.cpp src/Entity.h src/Interface.h
	g++ -c src/Interface.cpp -o build/Interface.o $(CFLAGS) $(LDFLAGS)

build/Race.o : src/Race.cpp src/Race.h
	g++ -c src/Race.cpp -o build/Race.o $(CFLAGS) $(LDFLAGS)

build/Scroll_Shooter.o : src/Scroll_Shooter.cpp src/Scroll_Shooter.h
	g++ -c src/Scroll_Shooter.cpp -o build/Scroll_Shooter.o $(CFLAGS) $(LDFLAGS)

build/Shooter.o : src/Shooter.cpp src/Shooter.h
	g++ -c src/Shooter.cpp -o build/Shooter.o $(CFLAGS) $(LDFLAGS)

build/Shooter_enemies_cars.o : src/Shooter_enemies_cars.cpp src/Shooter_enemies_cars.h
	g++ -c src/Shooter_enemies_cars.cpp -o build/Shooter_enemies_cars.o $(CFLAGS) $(LDFLAGS)


clean : 
	@rm -rf build/*.o build/test/*.o
	@rm bin/Runner-games  bin/Runner-games-test
	@echo "All files have been cleaned."