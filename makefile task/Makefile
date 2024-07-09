# Variables
CC = gcc
#the includes files location in case we did not include them in the source file
INCS = -I./include
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))
TARGET = $(BUILD_DIR)/app

# Directories to be created
DIRS = $(BIN_DIR) $(BUILD_DIR)

# Create directories using foreach
$(foreach dir, $(DIRS), $(shell mkdir -p $(dir)))

# Rules
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(BUILD_DIR)/*
	echo "cleaned succesfully"

.PHONY: all clean

