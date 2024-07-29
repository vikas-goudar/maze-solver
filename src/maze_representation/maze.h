#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <utility>
#include "node.h"


class Maze{
  private:
    int size;
    Node** arrayNodes;
    int maxNumNeighbours;

  public:
    Maze();
    Maze(int size , int maxNumNeighbours);
    ~Maze();

    void setArrayNodes();
    
    Node* getNode(int xCoord , int yCoord);
    Node* getRandomNode();

    void connectNodes(std::pair<int,int> src, std::pair<int,int> dest);
    std::vector<Node*> getConnections(std::pair<int,int> node);
};

#endif
