TARGET=supportticket
CXXFLAGS=-Wall
CXX=g++

all: supportticket

clean:
	rm -f $(TARGET)

supportticket:
	$(CXX) $(CXXFLAGS) supportticket.cpp -o $(TARGET)
