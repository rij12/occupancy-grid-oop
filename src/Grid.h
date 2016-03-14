//
// Created by rich on 11/03/16.
//

#ifndef OCCUPANCY_GRID_OOP_GRID_H
#define OCCUPANCY_GRID_OOP_GRID_H
#include <vector>
#include <ostream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
class Grid{

public:
    Grid();
    ~Grid();
    Grid::Grid(vector<vector<double>> poses, vector<vector<double >> ranges);
    void printGrid();

private:
    void intialiseGrid(vector<vector<int>> &grid);
    vector<vector<int>> grid;
    void buildingGrid(std::vector<std::vector<double>> poses,
                      std::vector<std::vector<double>> ranges,
                      std::vector<std::vector<int>> & grid);
    const double MAX_RANGE_OF_SENORS = 2.5;
    const int GRID_WIDTH = 50;
    const int DGREE_MULTIPLER = 45;
};

#endif //OCCUPANCY_GRID_OOP_GRID_H
