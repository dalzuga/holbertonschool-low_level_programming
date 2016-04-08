CC=gcc
CFLAGS=-c -Wall -pedantic -Werror -Wextra
FILES=0-absolute 0-contact_strings 0-first_digit 0-lowercase 0-print_number 0-uppercase_string 1-cap_string 1-nconcat_strings 1-power 1-swap_int 1-uppercase 2-print_array 2-square_root 2-string_copy 2-str_len 3-is_prime_number 3-print_string 3-string_ncopy 4-positive_or_not 4-reverse_string 4-strings_compare 5-reverse_array 5-string_to_integer
SOURCES = src/$(FILES).c
OBJECTS = src/$(FILES).o

all: libholberton.a

libholberton.a: $(OBJECTS)
	ar -rc libholberton.a $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)

re: $(OJBECTS)
