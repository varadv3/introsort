CC = gcc

BUILD_DIR = build
INCLUDE_DIRS := -Ilibsort/

SRCS := ./libsort/sort.c
OBJS := $(SRCS:.c=.o)

LIB_OUT := $(BUILD_DIR)/libsort.so

EXEC := $(BUILD_DIR)/main
EXEC_SRCS := main.c

all: $(LIB_OUT) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

%.o: %.c
	$(CC) $(INCLUDE_DIRS) -c $? -o $@

$(LIB_OUT): $(BUILD_DIR) $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

$(EXEC): $(EXEC_SRCS)
	$(CC) $(INCLUDE_DIRS) $? -o $@ -L$(BUILD_DIR) -lsort

clean:
	rm -rf $(BUILD_DIR) $(OBJS)
