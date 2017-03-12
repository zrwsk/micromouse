all: main

%: %.cpp
	g++ -std=c++11 $< -lboost_system -lboost_filesystem -o $@

