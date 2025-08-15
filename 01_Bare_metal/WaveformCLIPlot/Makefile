SRC_DIR := src
BUILD_DIR = build

SRC := $(wildcard $(SRC_DIR)/*.c)


#OBJ := $(SRC:.c=.o)
#OBJ := $(SRC:.c=$.o)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)

CC := gcc
COPS := -Wall -Wextra -Iinclude
TARGET = plot

all: $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET).exe

$(TARGET): $(OBJ)
	$(CC) $(COPS) -o $@ $(OBJ)

#%.o: %.c
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	$(CC) $(COPS) -c $< -o $@	