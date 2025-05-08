# ===== Configuration =====
SRC_DIR     = src
INCLUDE_DIR = include
BUILD_DIR   = build
LIB_DIR     = lib
BIN_DIR     = bin

CC          = g++
CXX         = g++
AR          = ar

# Flags for both C and C++
COMMON_FLAGS = -I$(INCLUDE_DIR) -fPIC
CCFLAGS     = $(COMMON_FLAGS) -lX11
CXXFLAGS    = $(COMMON_FLAGS) -std=c++11
LDFLAGS     = -lX11

# Source files
MAIN_SRC    = $(SRC_DIR)/main.cpp  # Example/test application
ALL_CPP     = $(wildcard $(SRC_DIR)/*.cpp)
CPP_NO_MAIN = $(filter-out $(MAIN_SRC), $(ALL_CPP))
C_SRC       = $(wildcard $(SRC_DIR)/*.c)

# Object files
LIB_OBJ     = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_NO_MAIN)) \
              $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRC))

# ===== Targets =====
.PHONY: all lib app clean run trace install

all: lib app

# === Library build ===
lib: $(LIB_DIR)/libxui.a

$(LIB_DIR)/libxui.a: $(LIB_OBJ)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^
	@echo "--> Static library built at $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CCFLAGS)

# === Test application build ===
app: $(BIN_DIR)/xui-test

$(BIN_DIR)/xui-test: $(MAIN_SRC) $(LIB_DIR)/libxui.a
	@mkdir -p $(BIN_DIR)
	$(CXX) $< -o $@ -L$(LIB_DIR) -lxui $(CXXFLAGS) $(LDFLAGS)
	@echo "--> Test application built at $@"

# === Installation ===
install: lib
	@mkdir -p /usr/local/include/xui
	cp $(INCLUDE_DIR)/*.h /usr/local/include/xui/
	cp $(LIB_DIR)/libxui.a /usr/local/lib/
	@echo "--> Library installed system-wide"

# === Clean everything ===
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR)
	@echo "--> Cleaned up build artifacts"

# === Run test app ===
run: app
	./$(BIN_DIR)/xui-test

# === strace the app ===
trace: app
	strace ./$(BIN_DIR)/xui-test