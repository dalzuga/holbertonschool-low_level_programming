GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC	:= print_char.c 0-print_content.c
OBJECTS	:= $(SRC:.c=.o)
TARGET	:= 0-print_content

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJECTS): $(SRC)

clean:
	rm -f $(OBJECTS) $(TARGET)

re: $(OBJECTS)
