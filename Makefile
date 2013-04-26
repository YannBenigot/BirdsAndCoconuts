SUBDIRS = GraphicPrimitives HitboxComponents GraphicComponents TrajectoryComponents
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(foreach dir, $(SUBDIRS), $(patsubst %.cpp,%.o,$(wildcard $(dir)/*.cpp)))
DEPS = $(wildcard *.hpp) $(foreach dir, $(SUBDIRS), $(wildcard $dir/*.hpp))
CFLAGS = -O0 -std=c++0x -I$(PWD) -g #-pedantic-errors -Wall -Wextra -Werror 
LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -g
EXECUTABLE = game

all: $(OBJS) $(EXECUTABLE)

%.o: %.cpp $(DEPS)
	g++ $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJS)
	g++ $(CFLAGS) $(LDFLAGS) $^ -o $@

$(EXECUTABLE).static: $(OBJS)
	g++ $(CFLAGS) $(LDFLAGS) --static $^ -o $(EXECUTABLE).static

clean:
	rm -f $(OBJS) $(EXECUTABLE)
