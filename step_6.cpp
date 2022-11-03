//step5.cpp

#include "Account.h"
#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include<iomanip>
#include "utils.h"
#include "visual.h"


using namespace std;

struct deleter {

	template <class T> void operator () (T* p) { delete p; }

};
vector<string> read_txt(string filepath)
{
	vector<string>vc;
	ifstream inf(filepath);
	string data;
	while (getline(inf, data))
	{
		vc.push_back(data);
	}
	inf.close();
	return vc;
}


int main()
{
	print_frame();
	initial_interface();
}