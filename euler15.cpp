/*
	Project 		Euler
	Problem: 		11
	Language: 		C++
	Description: 	Starting in the top left corner of a 2×2 grid, and only being able 
					to move to the right and down, there are exactly 6 routes to the bottom 
					right corner. How many such routes are there through a 20×20 grid?
*/
#include <iostream>

unsigned long long TraverseGrid(int x, int y, int fast);
unsigned long long TraverseNodeSlow(unsigned int colSize, unsigned int node, unsigned int dest);
double TraverseNodeFast(unsigned int colSize, unsigned int node, unsigned int dest);

int ** Nodes;

int main(int argc, char** argv)
{
	unsigned int GridSize[2] {4, 4};

	if(argc == 2)
	{
		GridSize[0] = atoi(argv[1]);
		GridSize[1] = atoi(argv[1]);
	}
	else if(argc == 3)
	{
		GridSize[0] = atoi(argv[1]);
		GridSize[1] = atoi(argv[2]);
	}

	printf("A %dx%d grid has...%llu paths.\n",GridSize[0],GridSize[1],TraverseGrid(GridSize[0],GridSize[1],1));
	printf("A %dx%d grid has...%llu paths.\n",GridSize[0],GridSize[1],TraverseGrid(GridSize[0],GridSize[1],0));

	return 0;
}


unsigned long long TraverseGrid(int sizeX, int sizeY, int fast)
{
	int nodeCount = (sizeX+1)*(sizeY+1);
	if(fast)
	{
		Nodes = new int * [nodeCount];
		for(int i = 0; i < nodeCount; ++i)
		{
			Nodes[i] = new int[2] {};
		}

		long long paths = TraverseNodeFast(sizeX+1, 0, nodeCount-1);

		for(int i = 0; i < sizeX; ++i)
		{
			delete Nodes[i];
		}
		delete [] Nodes;

		return paths;
	}
	// Nodes in Grid = (X + 1) * (Y + 1)
	return TraverseNodeSlow(sizeX+1, 0, nodeCount-1);
}

unsigned long long TraverseNodeSlow(unsigned int x, unsigned int node, unsigned int dest)
{
	// At destination
	if(node == dest)
	{
		return 1;
	}

	long long leftPaths = 0, rightPaths = 0;
	// Move Right
	if((node+1) % x != 0) leftPaths = TraverseNodeSlow(x, node+1, dest);
	// Move Down
	if(node + x <= dest) rightPaths = TraverseNodeSlow(x, node+x, dest);

	return leftPaths+rightPaths;
}

double TraverseNodeFast(unsigned int x, unsigned int node, unsigned int dest)
{
	if(node == dest) return 1;

	// If we have been here already return # of paths to dest
	if(Nodes[node][0] == 1) return Nodes[node][1];

	// Mark as visited
	Nodes[node][0] = 1;

	// Move Right
	if((node+1) % x != 0) Nodes[node][1] += TraverseNodeFast(x, node+1, dest);
	// Move Down
	if(node + x <= dest) Nodes[node][1] += TraverseNodeFast(x, node+x, dest);


	return Nodes[node][1];
}