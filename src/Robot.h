//
// Created by rich on 11/03/16.
//

#ifndef OCCUPANCY_GRID_OOP_ROBOT_H
#define OCCUPANCY_GRID_OOP_ROBOT_H

#include <ostream>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

class Robot {

public:
    Robot();
    ~Robot();
    const vector<vector<double>> &getRanges();
    const vector<vector<double>> &getPoses();
    static double getCellIndexY(double y);
    static double getCellIndexX(double x);
    static double getXCoordinate(double x_r, double sensors_range, double senor_alpha, double senor_beta);
    static double getYCoordinate(double y_r, double senor_range, double senor_alpha, double senor_beta);

private:

    std::vector<std::vector<double>> poses;
    std::vector<std::vector<double>> ranges;
    static double  convertToRadians(double degrees);
    void readPosesData(std::vector<std::vector<double>> &poses);
    void readRangeData(std::vector<std::vector<double>> &ranges);
    static constexpr  double RADS_TO_DEGREES = 57.2958;
    static constexpr  double GRID_OFF_SET = 0.2;
};

#endif //OCCUPANCY_GRID_OOP_ROBOT_H
