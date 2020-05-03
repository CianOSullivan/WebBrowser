all: link

link: compile
	g++ src/out/*.o -o main -lraylib -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor

compile: clean
	g++ -c src/*.cpp -lraylib -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
	mv *.o src/out/

clean:
	rm -f main
	rm -fr src/out/*.o
