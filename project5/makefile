TARGET = proj5
HEADERS = Vehicle.h Car.h #List of all header files
SRCS = proj5.cpp Vehicle.cpp Car.cpp #List of all source files
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall

#Rule that defers make all to the TARGET rule
all: $(TARGET)

#Rule to compile a single object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)