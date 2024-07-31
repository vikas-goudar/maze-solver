#ifndef ALDOUS_BRODER_H
#define ALDOUS_BRODER_H

#include "../maze_representation/maze.h"

class AldousBroder{
  private:
    long long visitedMask;
    long long visitedNum;
    int size;

  public:
    AldousBroder(Maze* maze);
    void generateMaze(Maze* maze);
    int isComplete();
    int isVisited(Node* node);
    void markVisited(Node* node);
};

#endif
