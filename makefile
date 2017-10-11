CFLAGS = -Wall -Werror
SOURCES = src/main.cpp src/Entity.cpp src/Player.cpp src/Background.cpp src/Hedge.cpp src/Direction.cpp src/Effect.cpp src/Scroll_Shooter_Enemies_Car.cpp src/Interface.cpp src/Bullet.cpp src/Race.cpp src/Scroll_Shooter.cpp src/Shooter.cpp src/Shooter_enemies_car.cpp src/Menu.cpp src/Movable.cpp src/Unit.cpp
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = build/main.o build/Background.o build/Bullet.o build/Direction.o build/Effect.o build/Scroll_Shooter_Enemies_Car.o build/Entity.o build/Hedge.o build/Interface.o build/Player.o build/Race.o build/Scroll_Shooter.o build/Shooter.o build/Shooter_enemies_car.o build/Menu.o build/Movable.o build/Unit.o

.PHONY: clean all Runner-games test

all :
	make bin/Runner-games

bin/Runner-games : $(OBJECTS)
	g++ build/main.o build/Background.o build/Bullet.o build/Direction.o build/Effect.o build/Scroll_Shooter_Enemies_Car.o build/Entity.o build/Hedge.o build/Interface.o build/Player.o build/Race.o build/Scroll_Shooter.o build/Shooter.o build/Shooter_enemies_car.o build/Menu.o build/Movable.o build/Unit.o -o bin/Runner-games $(CFLAGS) $(LDFLAGS)

build/main.o : $(SOURCES)
	g++ -c src/main.cpp -o build/main.o $(CFLAGS) $(LDFLAGS)

build/Entity.o : src/Entity.cpp src/Entity.h
	g++ -c src/Entity.cpp -o build/Entity.o $(CFLAGS) $(LDFLAGS)

build/Player.o : src/Player.cpp src/Player.h src/Unit.h
	g++ -c src/Player.cpp -o build/Player.o $(CFLAGS) $(LDFLAGS)

build/Unit.o : src/Unit.cpp src/Unit.h 
	g++ -c src/Unit.cpp -o build/Unit.o $(CFLAGS) $(LDFLAGS)

build/Background.o : src/Background.cpp src/Background.h src/Entity.h
	g++ -c src/Background.cpp -o build/Background.o $(CFLAGS) $(LDFLAGS)

build/Bullet.o : src/Bullet.cpp src/Bullet.h src/Entity.h
	g++ -c src/Bullet.cpp -o build/Bullet.o $(CFLAGS) $(LDFLAGS)

build/Direction.o : src/Direction.cpp src/Direction.h src/Entity.h
	g++ -c src/Direction.cpp -o build/Direction.o $(CFLAGS) $(LDFLAGS)

build/Effect.o : src/Effect.cpp src/Effect.h src/Entity.h
	g++ -c src/Effect.cpp -o build/Effect.o $(CFLAGS) $(LDFLAGS)

build/Hedge.o : src/Hedge.cpp src/Hedge.h src/Entity.h
	g++ -c src/Hedge.cpp -o build/Hedge.o $(CFLAGS) $(LDFLAGS)

build/Interface.o : src/Interface.cpp src/Entity.h src/Interface.h
	g++ -c src/Interface.cpp -o build/Interface.o $(CFLAGS) $(LDFLAGS)

build/Menu.o : src/Menu.cpp src/Menu.h
	g++ -c src/Menu.cpp -o build/Menu.o $(CFLAGS) $(LDFLAGS)

build/Movable.o : src/Movable.cpp src/Movable.h src/Entity.h src/Direction.h
	g++ -c src/Movable.cpp -o build/Movable.o $(CFLAGS) $(LDFLAGS)

build/Race.o : src/Race.cpp src/Race.h
	g++ -c src/Race.cpp -o build/Race.o $(CFLAGS) $(LDFLAGS)

build/Scroll_Shooter.o : src/Scroll_Shooter.cpp src/Scroll_Shooter.h
	g++ -c src/Scroll_Shooter.cpp -o build/Scroll_Shooter.o $(CFLAGS) $(LDFLAGS)
	
build/Scroll_Shooter_Enemies_Car.o : src/Scroll_Shooter_Enemies_Car.cpp src/Scroll_Shooter_Enemies_Car.h src/Entity.h
	g++ -c src/Scroll_Shooter_Enemies_Car.cpp -o build/Scroll_Shooter_Enemies_Car.o $(CFLAGS) $(LDFLAGS)

build/Shooter.o : src/Shooter.cpp src/Shooter.h
	g++ -c src/Shooter.cpp -o build/Shooter.o $(CFLAGS) $(LDFLAGS)

build/Shooter_enemies_car.o : src/Shooter_enemies_car.cpp src/Shooter_enemies_car.h
	g++ -c src/Shooter_enemies_car.cpp -o build/Shooter_enemies_car.o $(CFLAGS) $(LDFLAGS)

clean : 
	@rm -rf build/*.o build/test/*.o
	@rm bin/Runner-games  bin/Runner-games-test
	@echo "All files have been cleaned."
