# all: main

# %: %.cpp
# 	g++ -std=c++11 $< -lboost_system -lboost_filesystem -o $@
all:
	g++ -o mazesolver.out sensor.cpp maze.cpp mouse.cpp applicationui.cpp main.cpp -lboost_system -lboost_filesystem -lncurses -std=c++11 