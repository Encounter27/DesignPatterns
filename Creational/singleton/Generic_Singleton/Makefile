CC=g++
INCLUDE=./Include
CPP=./Cpp
OBJ=*.o
SRC=main.cpp
OP=binary


exec: \
compile
	echo "\n\nOUTPUT OF THE PROGRAM:"
	./binary
	echo "\n\n"

compile: \
makeobjectfiles
	echo "\n\nCOMPILING"
	$(CC) -o $(OP) $(SRC) *.o  -I $(INCLUDE)

makeobjectfiles:
	echo "\n\nMAKING OBJECT FILES"
	$(CC) -c $(CPP)/* -I $(INCLUDE)

clean:
	rm *.o $(OP)
