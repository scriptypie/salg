
INCLUDES=./salg/

FLAGS= -std=c++17 -Wall

make:
	clang++ $(FLAGS) -o salgtest main.cpp

run:
	./salgtest
