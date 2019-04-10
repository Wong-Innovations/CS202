# Macro for compiler command
CXX = g++
# Macro for compiler flags
CXX_FLAGS = -Wall
all: projX
projX: projX.o DataType.o SmartPtr.o
	$(CXX) $(CXX_FLAGS) projX.o DataType.o SmartPtr.o -o projX
projX.o: projX.cpp DataType.h SmartPtr.h
	$(CXX) $(CXX_FLAGS) -c projX.cpp -o projX.o
DataType.o: DataType.cpp DataType.h
	$(CXX) $(CXX_FLAGS) -c DataType.cpp -o DataType.o
SmartPtr.o: SmartPtr.cpp SmartPtr.h
	$(CXX) $(CXX_FLAGS) -c SmartPtr.cpp -o SmartPtr.o
clean:
	rm -rf *.o projX