CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

UTILS_DIR = utils
UTILS_FILES = $(UTILS_DIR)/bitutils.c

main: main.c $(UTILS_FILES)
	$(CC) $(CFLAGS) -o main $^ -I$(UTILS_DIR)

adder: ex00/adder.c $(UTILS_FILES)
	$(CC) $(CFLAGS) -o adder $^ -I$(UTILS_DIR)

clean:
	rm -f adder
	rm -f main