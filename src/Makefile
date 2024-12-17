#
#
#mingw32-make for build

# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -std=c11

# Executable Name
TARGET = DungeonGame.exe

# Source Files
SRCS = DungeonGame.c player.c room.c item.c creature.c inventory.c data.c

# Header Files
HEADERS = player.h room.h item.h creature.h inventory.h data.h const.h

# Object Files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default Rule
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the directory
clean:
	del $(OBJS) $(TARGET)

# Rule to clean up object files
clean-obj:
	del $(OBJS)

# Phony targets (not files)
.PHONY: all clean clean-obj
