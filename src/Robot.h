
// @author Richard Price-Jones (rij12)

#ifndef OCCUPANCY_GRID_OOP_ROBOT_H
#define OCCUPANCY_GRID_OOP_ROBOT_H

#include <ostream>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Robot {

public:
    // Constructor
    Robot();
    // De-Constructor
    ~Robot();
    // Accessor member functions.
    const std::vector<std::vector<double>> &getRanges();
    const std::vector<std::vector<double>> &getPoses();

    // Converts X coordinate into cell index.
    // @param double - x coordinate.
    static double getCellIndexX(double x);

    // Converts Y coordinate into cell index.
    // @param double - y coordinate.
    static double getCellIndexY(double y);

    // Maps Raw robot and senor data to a grid coordinate.
    // @param double xPosition - Robot's current position in terms of it's x coordinate.
    // @param double sensorsValue - Robot's current sensor return value which has a max value of 2.5.
    // @param double sensorAlpha - Alpha represents the orientation of the robots sensor.
    // @param double sensorBeta - Beta represents the orientation of the robot
    static double getXCoordinate(double xPosition, double sensorValue, double sensorAlpha, double sensorBeta);

    // Maps Raw robot and senor data to a grid coordinate.
    // @param double yPosition - Robot's current position in terms of it's y coordinate.
    // @param double sensorsValue - Robot's current sensor return value which has a max value of 2.5.
    // @param double sensorAlpha - Alpha represents the orientation of the robots sensor.
    // @param double sensorBeta - Beta represents the orientation of the robot
    static double getYCoordinate(double yPosition, double sensorValue, double sensorAlpha, double sensorBeta);

private:
    // Vector of vectors data structure, that holds raw data
    // each vector holds one line of data.
    std::vector<std::vector<double>> poses;
    std::vector<std::vector<double>> ranges;

    // @param double degrees - divides degrees by RADS_IT_DEGREES
    // @return angle in radians.
    static double  convertToRadians(double degrees);

    // Reads provided text files, into poses and ranges data structures.
    // @param reference to a vector.
    void readPosesData(std::vector<std::vector<double>> &poses);

    // Reads provided text files, into poses and ranges data structures.
    // @param reference to a vector.
    void readRangeData(std::vector<std::vector<double>> &ranges);

    static constexpr  double RADS_TO_DEGREES = 57.2958;
    // Grid starts at -0.2, this is used to revert that offset
    // for easier calculation when convert coordinates to cell indexes.
    static constexpr  double GRID_OFF_SET = 0.2;
};

#endif //OCCUPANCY_GRID_OOP_ROBOT_H
