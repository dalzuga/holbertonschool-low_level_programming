GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC	:= print_char.c 1-copy_content.c
OBJECTS	:= $(SRC:.c=.o)
TARGET	:= 1-copy_content

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJECTS): $(SRC)

clean:
	rm -f $(OBJECTS) $(TARGET)

re: $(OBJECTS)
