TARGET = proj5
HEADERS = Vehicle.h Car.h #List of all header files
SRCS = proj5.cpp Vehicle.cpp Car.cpp #List of all source files
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall

#Rule that defers make all to the TARGET rule
all: $(TARGET)

proj5:
			$(CXX) $(CXX_FLAGS) $(SRCS)

clean:
	-rm -f *.o
	-rm -f $(TARGET)