/*
	Project 		Euler
	Problem: 		11
	Language: 		C++
	Description: 	Starting in the top left corner of a 2×2 grid, and only being able 
					to move to the right and down, there are exactly 6 routes to the bottom 
					right corner. How many such routes are there through a 20×20 grid?
*/
#include <iostream>

int TraverseGrid(int x, int y);
int TraverseNodeSlow(unsigned int colSize, unsigned int node, unsigned int dest);
int TraverseNodeFast(unsigned int colSize, unsigned int node, unsigned int dest);

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

	Nodes = new int * [GridSize[0]] {};
	for(int i = 0; i < GridSize[0]; ++i)
	{
		Nodes[i] = new int[GridSize[1]] {};
	}

	printf("A %dx%d grid has...%d paths.\n",GridSize[0],GridSize[1],TraverseGrid(GridSize[0],GridSize[1]));
	//std::cout << "Traversing a " << GridSize[0] << "x" << GridSize[1] << " grid..." << std::endl;
	//std::cout << TraverseGrid(GridSize[0], GridSize[1]) << " paths." << std::endl;

	return 0;
}


int TraverseGrid(int sizeX, int sizeY)
{
	// Nodes in Grid = (X + 1) * (Y + 1)
	return TraverseNodeSlow(sizeX+1, 0, (sizeX+1)*(sizeY+1)-1);
}

int TraverseNodeSlow(unsigned int x, unsigned int node, unsigned int dest)
{
	// At destination
	if(node == dest)
	{
		return 1;
	}

	int leftPaths = 0, rightPaths = 0;
	// Move Right
	if((node+1) % x != 0) leftPaths = TraverseNodeSlow(x, node+1, dest);
	// Move Down
	if(node + x <= dest) rightPaths = TraverseNodeSlow(x, node+x, dest);

	return leftPaths+rightPaths;
}

int TraverseNodeFast(unsigned int x, unsigned int node, unsigned int dest)
{
	return 0;
}