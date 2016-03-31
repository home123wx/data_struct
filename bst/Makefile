object = main.o bst.o
GCC=g++

all:main

main:$(object)
	$(GCC) $(object) -o $@

main.o:main.cpp
	$(GCC) -c $< -o $@

bst.o:bst_tree.cpp
	$(GCC) -c $< -o $@

clean:
	rm -f $(object)
	rm -f main
	rm -f main.o
