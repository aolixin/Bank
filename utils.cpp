#include"utils.h"
vector<string> split(string s, char c)
{
	s += c;
	vector<string>out;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != c)
		{
			temp += s[i];
		}
		else
		{
			out.push_back(temp);
			temp = "";
		}
	}
	return out;
}

vector<int>toInt(vector<string>s)
{
	int n = s.size();
	vector<int>out(n);
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			temp += (s[i][j] - '0') * pow(10, s[i].size() - j - 1);
		}
		out[i] = temp;
		temp = 0;
	}
	return out;
}


