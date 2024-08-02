#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../maze_generator.h"
#include <utility>
#include <random>

class BinaryTree{
  private:
    MazeGenerator* mazeGenerator;
    int size;
    std::random_device rd;
    std::uniform_int_distribution<> distrib;

  public:
    BinaryTree(MazeGenerator* mazeGenerator);
    void generateMaze();
    int getRandomSouthOrEast(std::pair<int,int> node);
}

#endif
