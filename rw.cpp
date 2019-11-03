#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
void addPlusPlus(ifstream& inStream, ofstream& outStream);
int main( )
{
	ifstream fin;
	ofstream fout;
	cout << "Begin editing files.\n";
	fin.open("/home/liuyq/cwork/find/helloworld.c");
	if (fin.fail( ))
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	fout.open("/home/liuyq/cwork/find/list.h");
	if (fout.fail( ))
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	addPlusPlus(fin, fout);
	fin.close( );
	fout.close( );
	cout << "End of editing files.\n";
	return 0;
}