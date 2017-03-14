# all: main

# %: %.cpp
# 	g++ -std=c++11 $< -lboost_system -lboost_filesystem -o $@
all:
	g++ -o mazesolver.out maze.cpp applicationui.cpp main.cpp -lboost_system -lboost_filesystem -std=c++11