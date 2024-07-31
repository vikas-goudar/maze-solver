#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <utility>
#include "node.h"


class Maze{
  private:
    int size;
    Node** arrayNodes;

  public:
    Maze();
    Maze(int size);
    ~Maze();

    void setArrayNodes();
    
    Node* getNode(std::pair<int,int> coord);
    Node* getRandomNode();
    int getSize();

    void connectNodes(std::pair<int,int> src, std::pair<int,int> dest , int bidi);
    std::vector<Node*> getConnections(std::pair<int,int> node);
    Node* getRandomConnection(std::pair<int,int> node);
};

#endif
