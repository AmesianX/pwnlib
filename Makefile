CXX = c++
AR = ar

CFLAGS = -Wall
LDFLAGS =
ARFLAGS = rcs

TARGET = libpwn.a

INCLUDEDIR = ./include
SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


$(TARGET) : $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(notdir $^)

%.o : %.cpp
	$(CXX) -I$(INCLUDEDIR) -c $(CFLAGS) $< -o $(notdir $@)


.PHONY: all clean

all : $(TARGET)

clean:
	rm -f $(TARGET) *.o