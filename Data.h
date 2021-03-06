#ifndef _DATA_H_
#define _DATA_H_
#include <iostream>
#include "Eigen/Eigen/Dense"
#include <fstream>
#include <vector>
using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;
class Data{
public:
	MatrixXd m;
	int tsNum, tsLen, testNum;
    MatrixXd testTS;
    vector<long> times;
	
	void read(string filename, int tNum, int ttLen);
	void readTestTS(int qsLen, int tstNum);
    void reinitial(int qsLen, int tstNum);
	void write(vector<int>* result);
    void testPick(int num);
    void writeTestTS(int i);
    
	
};

#endif