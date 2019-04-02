# Macro for compiler command
CXX = g++
# Macro for compiler flags
CXX_FLAGS = -Wall
all: proj7
proj7: proj7.o MyString.o
	$(CXX) $(CXX_FLAGS) proj7.o MyString.o -o proj7
proj7.o: proj7.cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c proj7.cpp -o proj7.o
MyString.o: MyString.cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c MyString.cpp -o MyString.o
clean:
	rm -rf *.o proj7