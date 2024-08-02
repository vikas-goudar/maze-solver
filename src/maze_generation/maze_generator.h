#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "../maze_representation/maze/maze.h"
#include <utility>

class MazeGenerator{
  private:
    long long visitedMask;
    long long visitedNum;
    Maze* maze;

	public:
    MazeGenerator(Maze* maze);
    
    int isComplete();
    int isVisited(std::pair<int,int> node);
    void markVisited(std::pair<int,int> node);
    std::pair<int,int> getRandomNode();
    std::pair<int,int> getRandomConnection(std::pair<int,int> node);
    void connectNodes(std::pair<int,int> sourceNode,std::pair<int,int> destinationNode,int bidi);
    int getSize();
};

#endif
