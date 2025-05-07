SRC_DIR     = src
BUILD_DIR   = build
LIB_DIR     = lib

CC          = g++
CXX         = g++
CCFLAGS     = -lX11
CXXFLAGS    = -std=c++17 -fPIC -Iinclude
LDFLAGS     = -lX11

MAIN_SRC    = $(SRC_DIR)/main.cpp
ALL_CPP     = $(wildcard $(SRC_DIR)/*.cpp)
CPP_NO_MAIN = $(filter-out $(MAIN_SRC), $(ALL_CPP))
C_SRC       = $(wildcard $(SRC_DIR)/*.c)

# Object files
LIB_OBJ     = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_NO_MAIN)) \
              $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRC))

.PHONY: app lib clean run trace

# === App build ===
app: $(BUILD_DIR)/app

$(BUILD_DIR)/app: $(ALL_CPP)
	mkdir -p $(BUILD_DIR)
	$(CC) $(ALL_CPP) -o $@ $(CCFLAGS)
	@echo "--> App built successfully."

# === Lib build (no main.cpp) ===
lib: $(LIB_DIR)/libxui.a

$(LIB_DIR)/libxui.a: $(LIB_OBJ)
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^
	@echo "--> Static library built at $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CXXFLAGS)

# === Clean everything ===
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)
	@echo "--> Cleaned up."

# === Run test app ===
run: $(BUILD_DIR)/app
	./$<

# === strace the app ===
trace: $(BUILD_DIR)/app
	strace ./$<
