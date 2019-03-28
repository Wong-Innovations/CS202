# Macro for compiler command
CXX = g++
# Macro for compiler flags
CXX_FLAGS = -Wall
all: proj6
proj6: proj6.o Car.o Vehicle.o
	$(CXX) $(CXX_FLAGS) proj6.o Car.o Vehicle.o -o proj6
proj6.o: proj6.cpp Car.h Vehicle.h
	$(CXX) $(CXX_FLAGS) -c proj6.cpp -o proj6.o
Car.o: Car.cpp Car.h Vehicle.h
	$(CXX) $(CXX_FLAGS) -c Car.cpp -o Car.o
Vehicle.o: Vehicle.cpp Vehicle.h
	$(CXX) $(CXX_FLAGS) -c Vehicle.cpp -o Vehicle.o
clean:
	rm -rf *.o proj6
