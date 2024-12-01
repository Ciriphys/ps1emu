CC = gcc
CFLAGS = -Wall -I Build/Include
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O3 -march=native

SRC_DIR = Build/Source
INC_DIR = Build/Include
BIN_DIR = Binaries
DEBUG_DIR = $(BIN_DIR)/Debug
RELEASE_DIR = $(BIN_DIR)/Release

SOURCES = $(wildcard $(SRC_DIR)/*.c)
DEBUG_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(DEBUG_DIR)/%.o, $(SOURCES))
RELEASE_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(RELEASE_DIR)/%.o, $(SOURCES))
DEBUG_TARGET = $(DEBUG_DIR)/emud
RELEASE_TARGET = $(RELEASE_DIR)/emur

all: debug

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_TARGET)

release: CFLAGS += $(RELEASE_FLAGS)
release: $(RELEASE_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJECTS)
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(RELEASE_TARGET): $(RELEASE_OBJECTS)
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: debug
	@mkdir -p $(DEBUG_DIR)/Roms
	@cp -r Roms/* $(DEBUG_DIR)/Roms || true
	@./$(DEBUG_TARGET)

run-release: release
	@mkdir -p $(RELEASE_DIR)/Roms
	@cp -r Roms/* $(RELEASE_DIR)/Roms || true
	@./$(RELEASE_TARGET)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all debug release run run-release clean