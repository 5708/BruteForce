#include "BruteForce.h"
using Eigen::VectorXd;
BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}
void BruteForce::initial(string filename, int tsNum, int ttLen)
{
    cout<<"start initial"<<endl;
	data.read(filename, tsNum, ttLen);
	cout<<"finish initial"<<endl;
}

void BruteForce::subsequenceQuery(VectorXd qs, double epsilon)
{
	int tsNum, tsLen, qsLen;
	MatrixXd tempM,qsMatrix;
	VectorXd tempD;

	tsNum = data.tsNum;
	tsLen = data.tsLen;
	qsLen = qs.size();
	tempM.resize(tsNum, qsLen);
	tempD.resize(tsNum);
	qsMatrix.resize(1,qsLen);
	qsMatrix.row(0) = qs;
	queryResult.clear();
	for(int i = 0; i < (tsLen - qsLen + 1); ++i)
	{
		tempM = data.m.block(0,i,tsNum, qsLen);
			tempD = tempM.rowwise().operator-(qsMatrix.row(0)).array().square().matrix().rowwise().sum();
			for(int j = 0; j < tsNum; ++j)
			{
				if(tempD(j) < epsilon)
				{
					queryResult.push_back(j*1000+i);
				}
			}
	}
	
}
	
void BruteForce::reinitial(int tLen, int tstNum)
{
	data.readTestTS(tLen, tstNum);

}