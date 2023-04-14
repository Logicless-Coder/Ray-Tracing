main: main.cpp vec3.o color.o ray.o
	g++ vec3.o color.o ray.o main.cpp -o main

vec3.o: vec3.h vec3.cpp
	g++ -c vec3.cpp -o vec3.o

color.o: color.h color.cpp vec3.o
	g++ -c color.cpp -o color.o

ray.o: ray.h ray.cpp vec3.o
	g++ -c ray.cpp -o ray.o

clean: 
	rm -rf main vec3.o color.o ray.o
