CC=gcc
CFLAGS=-c -Wall -pedantic -Werror -Wextra
FILES=0-absolute.c 0-contact_strings.c 0-first_digit.c 0-lowercase.c 0-print_number.c 0-uppercase_string.c 1-cap_string.c 1-nconcat_strings.c 1-power.c 1-swap_int.c 1-uppercase.c 2-print_array.c 2-square_root.c 2-string_copy.c 2-str_len.c 3-is_prime_number.c 3-print_string.c 3-string_ncopy.c 4-positive_or_not.c 4-reverse_string.c 4-strings_compare.c 5-reverse_array.c 5-string_to_integer.c
SOURCES = $(FILES)
OBJECTS = $(SOURCES:.c=.o)
VPATH = src

all: libholberton.a

libholberton.a: $(OBJECTS)
	ar -rc libholberton.a $(OBJECTS)

$(OBJECTS): $(SOURCES)

clean:
	rm $(OBJECTS)

re: $(OJBECTS)
