override CXX := C:\Users\AshKiller47\Documents\MinGW\bin\g++.exe

all: compile move link execute

compile:
	$(CXX) -std=c++17 -c src\StarFleet.cpp -c src\StarFleet\\*.cpp -IC:\Retrofit\Libraries\SFML-2.6.1\include -Iinclude -DSFML_STATIC

move:
	move /Y "*.o" obj

link:
	$(CXX) -static obj\\*.o -o bin\StarFleet -LC:\Retrofit\Libraries\SFML-2.6.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

execute:
	cd bin && StarFleet

clean:
	del obj\\*.o bin\StarFleet.exe