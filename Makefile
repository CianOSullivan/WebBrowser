all: link

link: compile
	g++ src/out/*.o -o main

compile: clean
	g++ -c src/*.cpp
	mv *.o src/out/

clean:
	rm -f main
	rm -fr src/out/*.o