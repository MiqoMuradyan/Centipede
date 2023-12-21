# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic 
LDFLAGS = -lncurses 

# Source files
SRCS = main.cpp centipede.cpp board.cpp game.cpp screen.cpp character.cpp menu.cpp
# Header files
HEADERS = centipede.hpp board.hpp game.hpp screen.hpp character.hpp  menu.hpp enums.hpp
# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = centipede_game

# Default target
all: $(EXEC)

# Linking the object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compiling source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(EXEC)