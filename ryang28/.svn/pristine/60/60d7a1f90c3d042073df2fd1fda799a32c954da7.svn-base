/* Your code here! */
#ifndef MAZE_H
#define MAZE_H

#include "dsets.h"
#include "png.h"
#include "stdlib.h"

class SquareMaze{
public:
	SquareMaze();
	void makeMaze(int width, int height);
	bool canTravel(int x, int y, int dir) const;
	void setWall(int x, int y, int dir, bool exists);
	vector<int> solveMaze();
	PNG* drawMaze() const;
	PNG* drawMazeWithSolution();
	bool forbidden(int r, int dir);

private:
	class cell{
	public:
		cell():right(true), bottom(true), hasVisited(false){}
		bool right;
		bool bottom;
		bool hasVisited;
	};

	int mWidth;
	int mHeight;
	// 2-D 
	vector<vector<cell>> cells;
	DisjointSets maze;

};

#endif