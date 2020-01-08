#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Position
{
    int x = 0;
    int y = 0;
};

const int GRID_SIZE = 550;
int grid[GRID_SIZE][GRID_SIZE] = {};

int main()
{
    int middleX = GRID_SIZE / 2;
    int middleY = GRID_SIZE / 2;

    int curX = middleX;
    int curY = middleY;
    int curVal = 1;

    grid[curX][curY] = curVal;
    ++curVal;

    int xDir = 1;
    int yDir = 0;

    while (true)
    {
        curX += xDir;
        curY += yDir;

        if (curX < 0 || curY < 0 || curX >= GRID_SIZE || curY >= GRID_SIZE)
        {
            break;
        }

        grid[curX][curY] = curVal;

        if (curVal == 277678)
        {
            int xDistance = abs(curX - middleX);
            int yDistance = abs(curY - middleY);

            int totalDistance = xDistance + yDistance;

            std::cout << "Distance " << totalDistance << std::endl;
            std::cin.get();
            return 0;
        }

        ++curVal;

        // we're going right
        if (xDir == 1 && yDir == 0)
        {
            // check up
            if (grid[curX][curY - 1] == 0)
            {
                // start going up!
                xDir = 0;
                yDir = -1;
            }
        }
        // we're going up
        else if (xDir == 0 && yDir == -1)
        {
            // check left
            if (grid[curX - 1][curY] == 0)
            {
                // start going left
                xDir = -1;
                yDir = 0;
            }
        }
        // we're going left
        else if (xDir == -1 && yDir == 0)
        {
            // check down
            if (grid[curX][curY + 1] == 0)
            {
                // start going down!
                xDir = 0;
                yDir = 1;
            }
        }
        // we're going down
        else if (xDir == 0 && yDir == 1)
        {
            // check right
            if (grid[curX + 1][curY] == 0)
            {
                // start going right
                xDir = 1;
                yDir = 0;
            }
        }
    }

	return 0;
}
