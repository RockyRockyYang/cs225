/* Your code here! */
#include "maze.h"
#include "time.h"
#include <map>
#include <queue>
#include <stack>

SquareMaze::SquareMaze(){}

void SquareMaze::makeMaze(int width, int height)
{
	// cleanup if already exist
	maze.clear();
	for(unsigned long i=0; i< cells.size(); i++){
		cells[i].erase(cells[i].begin(), cells[i].end());
	}

	if(width <2 || height <2)
		return;
	mWidth = width;
	mHeight = height;
	maze.addelements(width*height);
	for(int i=0; i< width; i++){
		vector<cell> temp;
		for(int j=0; j< height; j++){
			temp.push_back(cell());
		}
		cells.push_back(temp);
	}
	srand(time(NULL));                                                                                                                                                 ;
	while(maze.fsize(0) != (0-mWidth*mHeight)){
		int rand1 = rand() % (mWidth*mHeight);
		int hor = rand1 % mWidth;
		int ver = rand1 / mWidth;
		int dir = rand() % 2;
		if(!forbidden(rand1,  dir)){
			if(dir == 0){
				setWall(hor, ver, 0, false);
			}
			if(dir == 1){
				setWall(hor, ver, 1, false);
			}
		}
	}

}

bool SquareMaze::forbidden(int r, int dir)
{
	if(dir==0 && r%mWidth==mWidth-1){
		return true;
	}
	if(dir==1 && r/mWidth==mHeight-1){
		return true;
	}
	if(dir==0)
		return maze.find(r)==maze.find(r+1);
	if(dir==1)
		return maze.find(r)==maze.find(r+mWidth);
	return false;
}

bool SquareMaze::canTravel(int x, int y, int dir) const
{
	if((dir== 0 && x ==mWidth-1) || (dir== 1 && y == mHeight-1) || (dir==2 && x==0) || (dir==3 && y==0) || x<0 ||
	 x >= mWidth || y<0 || y >= mHeight)
		return false;
	if(dir ==0)
		return !cells[x][y].right;
	else if(dir ==1)
		return !cells[x][y].bottom;
	else if(dir == 2)
		return canTravel(x-1, y, 0);
	else if(dir == 3)
		return canTravel(x, y-1, 1);

	return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	if(dir == 0){
		cells[x][y].right = exists;
		if(!exists && maze.find(x+mWidth*y) != maze.find(x+mWidth*y +1))
			maze.setunion(x+mWidth*y, x+mWidth*y + 1);
	}
	if(dir == 1){
		cells[x][y].bottom = exists;
		if(!exists && maze.find(x+mWidth*y) != maze.find(x+mWidth*(y+1)))
			maze.setunion(x+mWidth*y, x+mWidth*(y+1));
	}
}

vector<int> SquareMaze::solveMaze()
{
	vector<int> solution;
	vector<bool> visited;

	for(int i=0; i< mHeight*mWidth; i++){
		visited.push_back(false);
	}
	queue<int> x;
	queue<int> y;
	x.push(0);
	y.push(0);
	map <int,int> pathMap;

	while(!x.empty()){
		int currX = x.front();
		int currY = y.front();
		visited[currY*mWidth + currX] = true;
		x.pop();
		y.pop();
		if(canTravel(currX, currY, 0) && !visited[currY*mWidth+currX+1]){
			x.push(currX +1);
			y.push(currY);
			pathMap[currX + currY*mWidth + 1] = currX + currY*mWidth;
		}
		if(canTravel(currX, currY, 1) && !visited[currX + (currY+1)*mWidth]){
			x.push(currX);
			y.push(currY +1);
			pathMap[currX + (currY+1)*mWidth] = currX + currY*mWidth;
		}
		if(canTravel(currX, currY, 2) && !visited[currX + currY*mWidth -1]){
			x.push(currX-1);
			y.push(currY);
			pathMap[currX + currY*mWidth -1] = currX + currY*mWidth;
		}
		if(canTravel(currX, currY, 3) && !visited[currX + (currY-1)*mWidth]){
			x.push(currX);
			y.push(currY-1);
			pathMap[currX + (currY-1)*mWidth] = currX + currY*mWidth;
		}
	}
	int max_i = 0;
	int max_count = 0;
	for(int i=0; i< mWidth; i++){
		int count = 0;
		int index = i + (mHeight-1) * mWidth;
		while(index != 0){
			index = pathMap[index];
			count++;
		}
		if(count > max_count){
			max_count = count;
			max_i = i;
		}
	}
	int exit_index = max_i + (mHeight-1) * mWidth;
	stack<int> step;
	while(exit_index != 0){
		int diff = exit_index - pathMap[exit_index];
		if(diff == 1)
			step.push(0);
		if(diff == -1)
			step.push(2);
		if(diff == mWidth)
			step.push(1);
		if(diff == (-1)*mWidth)
			step.push(3);
		exit_index = pathMap[exit_index];
	}
	while(!step.empty()){
		solution.push_back(step.top());
		step.pop();
	}
	return solution;
	
// 	vector <bool> visited;
// 	vector<int> step;

// 	queue<int> xx;
// 	queue<int> yy;
// 	xx.push(0);
// 	yy.push(0);	
// 	int temp1, temp2;
// 	int w = mWidth;
// 	int h = mHeight;

// 	for(int i=0; i<w*h; i++){
// 		step.push_back(0);
// 		visited.push_back(false);
// }
// 	//std::cout<< "haha"<<endl;
// 	while(!xx.empty()){
// 		temp1 = xx.front();
// 		temp2 = yy.front();
// 		xx.pop();
// 		yy.pop();
// 		visited[temp2*w+temp1] = true;
		
// 		if(canTravel(temp1, temp2, 0) && !visited[temp2*w+temp1+1]){
// 			xx.push(temp1+1);
// 			yy.push(temp2);
// 			step[temp2*w+temp1+1] = step[temp2*w+temp1]+1;
// }
// 		if(canTravel(temp1, temp2, 1)  && !visited[(temp2+1)*w+temp1]){
// 			xx.push(temp1);
// 			yy.push(temp2+1);
// 			step[(temp2+1)*w+temp1] = step[temp2*w+temp1]+1;
// }
// 		if(canTravel(temp1, temp2, 2)  && !visited[(temp2)*w+temp1-1]){
// 			xx.push(temp1-1);
// 			yy.push(temp2);
// 			step[temp2*w+temp1-1] = step[temp2*w+temp1]+1;
// }
// 		if(canTravel(temp1, temp2, 3) && !visited[(temp2-1)*w+temp1]){
// 			xx.push(temp1);
// 			yy.push(temp2-1);
// 			step[(temp2-1)*w+temp1] = step[temp2*w+temp1]+1;
// }
// }
// 	int best = 0;
// 	int count=0;
// 	for(int i=0; i<w; i++){
// 		if(step[(h-1)*w+i] > best){
// 			best = step[(h-1)*w+i];
// }
// }
// 	for(int i=0; i<w; i++){
// 		if(step[(h-1)*w+i]==best){
// 			count = i;
// 			break;
// }
// }
// 	//std::cout<<best<<endl;
// 	vector<int> out;
// 	int x = count;
// 	int y = h-1;
// 	while(x!=0 || y!=0){
// 		if(canTravel(x,y,0) && step[y*w+x+1]==step[y*w+x]-1){
// 			x++;
// 			out.push_back(2);}
// 		if(canTravel(x,y,1) && step[(y+1)*w+x]==step[y*w+x]-1){
// 			y++;
// 			out.push_back(3);}
// 		if(canTravel(x,y,2) && step[y*w+x-1]==step[y*w+x]-1){
// 			x--;
// 			out.push_back(0);}
// 		if(canTravel(x,y,3) && step[(y-1)*w+x]==step[y*w+x]-1){
// 			y--;
// 			out.push_back(1);}
// }
// 	std::reverse(out.begin(), out.end());
// 	return out;
}


PNG* SquareMaze::drawMaze() const
{
	PNG * pic = new PNG(mWidth*10 +1, mHeight*10 +1);
	for(int i=10; i<mWidth*10+1; i++){
		(*pic)(i,0)->red = 0;
		(*pic)(i,0)->green = 0;
		(*pic)(i,0)->blue = 0;
	}
	for(int i=0; i<mHeight*10+1; i++){
		(*pic)(0,i)->red = 0;
		(*pic)(0,i)->green = 0;
		(*pic)(0,i)->blue = 0;
	}
	for(int x=0; x< mWidth; x++){
		for(int y=0; y< mHeight; y++){
			if(!canTravel(x, y, 0)){
				for(int k=0; k<=10; k++){
				(*pic)((x+1)*10, y*10+k)->red = 0;
				(*pic)((x+1)*10, y*10+k)->green = 0;
				(*pic)((x+1)*10, y*10+k)->blue = 0;
				}
			}
			if(!canTravel(x, y, 1)){
				for(int k=0; k<=10; k++){
				(*pic)(x*10+k, (y+1)*10)->red = 0;
				(*pic)(x*10+k, (y+1)*10)->green = 0;
				(*pic)(x*10+k, (y+1)*10)->blue = 0;
				}
			}
		}
	}
	return pic;
}

PNG* SquareMaze::drawMazeWithSolution()
{
	PNG * pic = drawMaze();
	vector<int> out = solveMaze();
	int x=0;
	int y=0;
	for(int i=0; i<(int)out.size(); i++){
		if(out[i]==0){
			for(int i=0; i<=10; i++){
				(*pic)(x*10+5+i, y*10+5)->red = 255;
				(*pic)(x*10+5+i, y*10+5)->green = 0;
				(*pic)(x*10+5+i, y*10+5)->blue = 0;
			}
			x++;
		}
		if(out[i]==1){
			for(int i=0; i<=10; i++){
				(*pic)(x*10+5, y*10+5+i)->red = 255;
				(*pic)(x*10+5, y*10+5+i)->green = 0;
				(*pic)(x*10+5, y*10+5+i)->blue = 0;
			}
			y++;
		}
		if(out[i]==2){
			for(int i=0; i<=10; i++){
				(*pic)((x-1)*10+5+i, y*10+5)->red = 255;
				(*pic)((x-1)*10+5+i, y*10+5)->green = 0;
				(*pic)((x-1)*10+5+i, y*10+5)->blue = 0;
			}
			x--;
		}
		if(out[i]==3){
			for(int i=0; i<=10; i++){
				(*pic)(x*10+5, (y-1)*10+5+i)->red = 255;
				(*pic)(x*10+5, (y-1)*10+5+i)->green = 0;
				(*pic)(x*10+5, (y-1)*10+5+i)->blue = 0;
			}
			y--;
		}
	}

	for(int i=1; i<10; i++){
		(*pic)(x*10+i, y*10+10)->red = 255;
		(*pic)(x*10+i, y*10+10)->green = 255;
		(*pic)(x*10+i, y*10+10)->blue = 255;
	}
	return pic;
}