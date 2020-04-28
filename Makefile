all: compile

compile: clean
	g++ src/*.cpp -o main

clean:
	rm main
	rm -fr src/out/*.o