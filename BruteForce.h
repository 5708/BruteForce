#ifndef _BRUTEFORCE_H_
#define _BRUTEFORCE_H_
#include <iostream>
#include <vector>
#include "BPlus_tree.h"
#include "Data.h"


using namespace std;
using Eigen::VectorXd;
class BruteForce
{
public:
	BruteForce();
	~BruteForce();
	Data data;
	vector<int> queryResult;
	
	void initial(string filename, int tsNum, int ttLen);
	void subsequenceQuery(VectorXd qs, double epsilon);
    void reinitial(int tLen, int tstNum);


private:

};




#endif
