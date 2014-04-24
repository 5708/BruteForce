#include <iostream>
#include "BruteForce.h"
#include <time.h>
using namespace std;


int main()
{
	BruteForce bf;
	VectorXd v, tsLen;
	clock_t s,e;
    int testNum, epsilon;

    testNum = 1;
    tsLen.resize(3);
    tsLen<<11,23,46;
	epsilon = 1000000;
	bf.initial("./Data/h20v9EVI1D1_1.txt",10000,285);
    for(int a = 0; a < tsLen.size(); ++a)
    {
        cout<<"For tsLen = "<<tsLen(a)<<endl;
        bf.reinitial(tsLen(a), testNum);
        s = clock();
        for(int b = 0; b < testNum; ++b)
        {
			cout<<"Test"<<b<<":"<<endl;
			cout<<bf.data.testTS.row(b);
            bf.subsequenceQuery(bf.data.testTS.row(b),epsilon);
            cout<<"There are "<<bf.queryResult.size()<<" results"<<endl;
        }
        e=clock();
        cout<<"time"<<e-s<<"\n\n"<<endl;
        bf.data.times.push_back(e-s);
        //bf.data.writeTestTS(a);
    }
    bf.data.write(&(bf.queryResult));
	return 0;
}

/*
int main(){
	CBPlusTree B;
    MatrixXd matrix = MatrixXd::Random(10,10);
// 	MatrixXd* matrix = new MatrixXd(10,10);
// 	(*matrix)<< 11,44,55,
// 				33,22,66,
// 				99,88,77;
// 	Data d;
// 	d.read("../Data/h20v9EVI1D1_1.txt",10000,285);
	B.BPTbuild(&matrix);
	B.print();
	B.printData();
// 	vector<int> r = B.rangeQuery(23.0,87.0);
// 	for(int i = 0 ; i < r.size(); ++i)
// 		cout<<r[i]<<"--";
	cin.get();
}*/

