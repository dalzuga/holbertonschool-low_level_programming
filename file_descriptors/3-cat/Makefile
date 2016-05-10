GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC	:= print_char.c 3-cat.c
OBJECTS	:= $(SRC:.c=.o)
TARGET	:= 3-cat

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJECTS): $(SRC)

clean:
	rm -f $(OBJECTS) $(TARGET)

re: $(OBJECTS)
