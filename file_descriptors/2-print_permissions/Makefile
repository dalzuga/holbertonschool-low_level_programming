GCC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC	:= print_char.c 2-print_permissions.c
OBJECTS	:= $(SRC:.c=.o)
TARGET	:= 2-print_permissions

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJECTS): $(SRC)

clean:
	rm -f $(OBJECTS) $(TARGET)

re: $(OBJECTS)
