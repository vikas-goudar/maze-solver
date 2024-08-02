#ifndef ALDOUS_BRODER_H
#define ALDOUS_BRODER_H

#include "../maze_generator.h"
#include <utility>
#include <random>

class AldousBroder{
  private:
    MazeGenerator* mazeGenerator;

    std::random_device rd;
    std::uniform_int_distribution<> distrib;


  public:
    AldousBroder(MazeGenerator* mazeGenerator);
    void generateMaze();
		int getRandomDirection(std::pair<int,int> node);
};

#endif
