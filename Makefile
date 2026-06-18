CXX      = g++
CXXFLAGS = -g -Wall -std=c++14 -fmessage-length=0

# game.cpp = game logic, util.cpp = drawing primitives
OBJS   = util.o game.o
TARGET = game

# Linux/X11 link flags. freeglut provides libglut.
LIBS = -lglut -lGLU -lGL -lX11 -lm -pthread

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
