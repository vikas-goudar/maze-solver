#ifndef WILSON_H
#define WILSON_H

#include "../maze_generator.h"
#include <utility>
#include <random>
#include <vector>

class Wilson{
  private:
    MazeGenerator* mazeGenerator;
		
	public:
    AldousBroder(MazeGenerator* mazeGenerator);
    void generateMaze();
		std::vector<std::pair<int,int>> loopErasedWalk(std::pair<int,int> node);
}

#endif


