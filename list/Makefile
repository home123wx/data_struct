Obj = List.o main.o
GCC = g++
FLAGS = -g

all:main

main:${Obj}
	${GCC} ${FLAGS} ${Obj} -o $@
main.o:main.cpp
	${GCC} -c ${FLAGS} $< -o $@
List.o:List.cpp
	${GCC} -c ${FLAGS} $< -o $@

clean:
	rm *.o
	rm main
	
