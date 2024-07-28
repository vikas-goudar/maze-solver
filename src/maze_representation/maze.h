#ifndef MAZE_H
#define MAZE_H

#include "node.h"
#include <vector>

using namespace std;


class Maze{
  private:
    int size;
    Node** arrayNodes;
    int numNeighbours;

  public:
    Maze();
    Maze(int size , int numNeighbours);
    ~Maze();
    Node* getRandomNode();
    Node* getNode(int xCoord , int yCoord);
    void printNodes();
};

#endif
