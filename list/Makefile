Obj=List.o
GCC=g++
FLAGS= -g

all:List.o main

main:main.o
	${GCC} ${FLAGS} $< ${Obj} -o $@
main.o:main.cpp
	${GCC} -c ${FLAGS} $< -o $@
List.o:List.cpp
	${GCC} -c ${FLAGS} $< -o $@

clean:
	rm *.o
	rm main
	
