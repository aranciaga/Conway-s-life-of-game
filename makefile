CC=g++
CFLAGS=-c -DLINUX -I. -LSDL/lib
LDFLAGS=-lSDL
SOURCES=src/main.cpp src/game.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=conway

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
