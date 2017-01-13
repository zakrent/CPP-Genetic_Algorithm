
default: clean
build:
	g++ -c src/*.cpp src/*.h
	g++ *.o -o genetic.out

clean:
	rm *.o
