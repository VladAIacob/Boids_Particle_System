CC = g++
CFLAGS = -O3
LIBS = -lGL -lglut -lGLEW

SOURCE_PATH = src
BUILD_PATH = build
SRC_TREE := $(shell find $(SOURCE_PATH) -type d)
BUILD_TREE = $(subst $(SOURCE_PATH),$(BUILD_PATH),$(SRC_TREE))

MAIN = main
DEPS := $(shell find $(SOURCE_PATH) -name '*.h')
SRCS := $(shell find $(SOURCE_PATH) -name '*.cpp')
OBJS = $(subst $(SOURCE_PATH),$(BUILD_PATH),$(SRCS:.cpp=.o))

all: clean dir build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/$(MAIN) $^ $(LIBS)

dir:
	mkdir $(BUILD_TREE)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 
	
clean:
	rm -rfd $(BUILD_PATH)
