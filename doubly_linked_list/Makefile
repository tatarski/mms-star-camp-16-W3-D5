


build:
	mkdir build
	gcc -c dll.c -o dll.o
	gcc -c main.c -o main.o
	mv dll.o ./build
	mv main.o ./build
	gcc ./build/dll.o ./build/main.o -o exe
	mv exe ./build
clean:
	rm -rd build

run:
	./build/exe
	
