Obj=List.o
GCC=g++

all:List.o main

main:main.o
	${GCC} $< ${Obj} -o $@
main.o:main.cpp
	${GCC} -c $< -o $@
List.o:List.cpp
	${GCC} -c $< -o $@

clean:
	rm *.o
	rm main
	
