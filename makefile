CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC
AR = ar
ARFLAGS = rcs
TARGET_LIB = libansi_esc.a
TARGET_SO = libansi_esc.so
OBJS = ansi_esc.o

all: $(TARGET_LIB) $(TARGET_SO)

# Compile object
ansi_esc.o: ansi_esc.c ansi_esc.h
	$(CC) $(CFLAGS) -c ansi_esc.c -o ansi_esc.o

# Static library
$(TARGET_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Shared library
$(TARGET_SO): $(OBJS)
	$(CC) -shared -o $@ $^

# Example program
example: main.c $(TARGET_LIB)
	$(CC) main.c -L. -lansi_esc -o example

clean:
	rm -f $(OBJS) $(TARGET_LIB) $(TARGET_SO) example