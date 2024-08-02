choose a random node and mark it as visited

choose any univisited node and start a loop-erased walk { if at any point the path we are taking happens to intersect itself, remove the 
loop before continuing } until reaching a visited node
add the path to the maze, marking each of the nodes in the path as visited
repeat this process, until all the nodes are visited

creates an unbiased maze but is also slow
it start slow but ends fast because the algorithm searches for visited nodes which are less initialy but increase as the algorithm 
progresses

#ifndef WILSON_H
#define WILSON_H

#include "../maze_generator.h"
#include <utility>
#include <random>

class Wilson{
  private:
    MazeGenerator* mazeGenerator;
		int numUnvisited;
		
	public:
    AldousBroder(MazeGenerator* mazeGenerator);
    void generateMaze();
}

#endif


