# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Target executable
TARGET = $(BINDIR)/chess

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)
