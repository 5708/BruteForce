#include "Data.h"

using namespace std;

void Data::read(string filename, int tNum, int tLen)
{
	ifstream file;
	MatrixXd tempM;
	VectorXd tempV;
	
	tsNum = tNum;
	tsLen = tLen;;
	file.open(filename.c_str());
	m.resize(tsNum, tsLen);
	for(int i = 0; i < tsNum; ++i)
	{
		for(int j = 0; j < tsLen; ++j)
		{
			file >> m(i,j);
		}
	}
	file.close();
}

void Data::reinitial(int qsLen, int tstNum)
{
	readTestTS(qsLen, tstNum);
    
}
void Data::readTestTS(int qsLen, int tstNum)
{
	string filename;
	ifstream file;
	MatrixXd tempM;
	VectorXd tempV;

	testNum = tstNum;
	if(qsLen == 11)
	{
		filename = "./Data/testTS1.txt";
	}
	else if(qsLen == 23)
	{
		filename = "./Data/testTS2.txt";
	}
	else if(qsLen = 46)
	{
		filename = "./Data/testTS3.txt";
	}

	file.open(filename.c_str());
	if(!file)
	{
		cout<<"-------------------------"<<endl;
		cout<<"file open fail"<<endl;
		cout<<"-------------------------"<<endl;
	}
	testTS.resize(testNum, qsLen);
	for(int i = 0; i < testNum; ++i)
	{
		for(int j = 0; j < qsLen; ++j)
		{
			file >> testTS(i,j);
		}
	}
	file.close();
	cout<<testTS.row(0);

}


void Data::write(vector<int>* result)
{
	ofstream file;
	int timesSize;
	
// 	file.open ("output.txt");
// 	resultSize = (*result).size();
// 	for(int i = 0; i < resultSize; ++i)
// 		file << (*result)[i]<<"\n";
// 	file.close();
    
    file.open ("output_times.txt");
	timesSize = times.size();
	for(int i = 0; i < timesSize; ++i)
		file << times[i]<<"\n";
	file.close();
}


void Data::writeTestTS(int i)
{
    ofstream file;
    
    if(i == 0)
        file.open ("testTS1.txt");
    else if(i==1)
        file.open ("testTS2.txt");
    else if(i == 2)
        file.open ("testTS3.txt");
	for(int i = 0; i < testNum; ++i)
    {
        for(int j = 0; j < tsLen; ++j)
        {
            file << testTS(i,j)<<" ";
        }
        file<<endl;
    }
		
	file.close();
}