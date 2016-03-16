/*
 * @author Richard Price-Jones (rij12)
 *
 */


#include <tgmath.h>
#include <fstream>
#include <stdlib.h>
#include "Robot.h"

Robot::Robot() {
    readPosesData(poses);
    readRangeData(ranges);
}

Robot::~Robot() {

}

double Robot::getCellIndexX(double x){
    return round((x / 0.2) + GRID_OFF_SET );
}

double Robot::getCellIndexY(double y){
    return round((y / 0.2) + GRID_OFF_SET );
}

double Robot::getXCoordinate(double xPosition, double sensorValue, double sensorAlpha, double sensorBeta){

    double absoluteX;
    absoluteX = xPosition + sensorValue * cos(convertToRadians(sensorAlpha + sensorBeta));
    return absoluteX;
}

double Robot::getYCoordinate(double yPosition, double sensorValue, double sensorAlpha, double sensorBeta){

    double absoluteY;
    absoluteY = yPosition + sensorValue * sin(convertToRadians(sensorAlpha + sensorBeta));
    return absoluteY;
}

 double Robot::convertToRadians (double degrees){
    return   degrees / RADS_TO_DEGREES;
}

const vector<vector<double>> & Robot::getPoses(){
    return Robot::poses;
}

const vector<vector<double>> & Robot::getRanges() {
    return Robot::ranges;
}

void Robot::readRangeData(vector<vector<double> > & ranges) {

    //First we need a file object
    std::ifstream inFile;
    //File name
    string filename = "ranges_data.txt";
    double count = 0;
    double temp;
    inFile.open(filename);

    //Checks if the file can be open
    if (!inFile.is_open()) {
        cout << "file could not be opened " << filename << endl;
        cout << "Program terminating. " << endl;
        exit(EXIT_FAILURE);
    }

    // While no errors occur keep reading in data until end of the file.
    while (inFile.good()) {
        count++;


        //Fill Outer Vector.
        for (int i = 0; i < 40; i++) {
            vector<double> tempVector;
            //Fill inner Vector.
            for (int j = 0; j <= 7; j++) {
                inFile >> temp;
                tempVector.push_back(temp);
            }

            //Insert the temporary vector into outer vector ranges
            ranges.push_back(tempVector);
        }
    }
    //Check if any data was read.
    if (count == 0) {
        cout << "No data was read" << endl;
    }
    inFile.close();
}

void Robot::readPosesData(vector<vector<double>> & poses) {

    std::ifstream inFile;
    string filename = "poses_data.txt";

    double temp;
    double count = 0;
    //Opens the file with given filename
    inFile.open(filename);

    // Checks if the file can be open
    if (!inFile.is_open()) {
        cout << "file could not be opened " << filename << endl;
        cout << "Program terminating. " << endl;
        exit(EXIT_FAILURE);
    }
    while (inFile.good()) {
        count++;
        // Loops though outer vector
        for (int i = 0; i < 40; i++) {
            vector<double> tempVector;
            // Loops though Inner vector
            for (int j = 0; j < 3; j++) {
                inFile >> temp;
                tempVector.push_back(temp);
            }
            // Now push back the temp vector into the main vector.
            poses.push_back(tempVector);
        }
        cout << "PoseData NO. " << count << endl;
    }
    // Check if any data was read.
    if (count == 0) {
        cout << "No data was read" << endl;
    }
    inFile.close();
}