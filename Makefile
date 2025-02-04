run:
	./a.out

build-20:
	g++ -std=c++20 main.cpp
build-20-run:
	g++ -std=c++20 main.cpp && ./a.out
build-17:
	g++ -std=c++17 main.cpp
build-17-run:
	g++ -std=c++17 main.cpp && ./a.out

clangpp-17:
	clang++ --std=c++20 -lm -O2 main.cpp -o main
clangpp-17-run:
	clang++ --std=c++20 -lm -O2 main.cpp -o main
	./main

delete:
	rm ./a.out