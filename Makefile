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

delete:
	rm ./a.out