# all: main

# %: %.cpp
# 	g++ -std=c++11 $< -lboost_system -lboost_filesystem -o $@
all:
	g++ -o mazesolver.out applicationui.cpp main.cpp -lboost_system -lboost_filesystem