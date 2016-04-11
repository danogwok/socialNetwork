CXX = clang++ -g

CXXFLAGS = -Wall -Wextra -Werror

all: network

network: Main.o UserNetwork.o User.o Wall.o WallPost.o LinkedList.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f network *.o

