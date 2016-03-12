//
// Created by richard on 12/03/2016.
//

#ifndef OCCUPANCY_GRID_OOP_MAIN_H
#define OCCUPANCY_GRID_OOP_MAIN_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <vector>

void readPosesData(std::vector<std::vector<double>> & poses);
void readRangeData(std::vector<std::vector<double>> & ranges);
std::vector<std::vector<double> > poses;
std::vector<std::vector<double> > ranges;

#endif //OCCUPANCY_GRID_OOP_MAIN_H
