# Compile with all warnings and 1999 standard
CFLAGS = -Wall -std=c99

# Add files required in testing and main program
COMMON_SRCS = $(wildcard list/*.c) $(wildcard stack/*.c)

# Define sources required for targets
TEST_SRCS = $(COMMON_SRCS) $(wildcard test/*.c)

# Add specific test targets
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Add main entrypoint
MAIN_SRCS = main.c $(COMMON_SRCS)

# Define targets for all files required in both
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

main: $(MAIN_OBJS)

test: $(TEST_OBJS)
	gcc $(CFLAGS) -g -o test/test $(TEST_OBJS)

clean:
	if ls *.o 1>/dev/null 2>&1; then rm *.o; fi
	if ls **/*.o 1>/dev/null 2>&1; then rm **/*.o; fi
