#ifndef RECURSIVE_BACK_TRACKER_H
#define RECURSIVE_BACK_TRACKER_H

#include "../maze_generator.h"

class RecursiveBackTracker{
	private:
		MazeGenerator* mazeGenerator;

	public:
		RecursiveBackTracker(MazeGenerator* mazeGenerator);
		void generateMaze();

};

#endif
