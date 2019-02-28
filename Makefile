CC=gcc
CFLAGS=
LDFLAGS=
SOURCES=main.c
EXECUTABLE=sflash0unpack
all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(EXECUTABLE)
clean:
	rm -rf $(EXECUTABLE)
