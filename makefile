TARGET = ntnxexec 
LIBS = -lm
CC = g++
CFLAGS = -g -Wall -Wno-deprecated `pkg-config  --cflags libcurl`
LDFLAGS = `pkg-config --libs libcurl`
RM = `rm -f `

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ 

.PRECIOUS: $(TARGET) $(OBJECTS) 

$(TARGET): $(OBJECTS) 
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@ $(LDFLAGS)

clean:
	-rm -f $(OBJECTS) 
	-rm -f $(TARGET)

