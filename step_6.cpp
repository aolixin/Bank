//step5.cpp

#include "Account.h"
#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include<iomanip>
#include "utils.h"

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
	//全部命令
	vector<string>vc = read_txt("commands.txt");


	Date date(2008, 11, 1);//起始日期
	vector<Account*> accounts;//创建账户数组，元素个数为0
	
	char cmd;
	char type;
	int index, day;
	double amount, credit, rate, fee;
	string id, desc;
	Account* account;
	for (int i = 0; i < vc.size(); i++)
	{
		//显示日期和总金额
		// date.show();
		//cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";

		Date date1, date2;

		//一行命令
		vector<string>cmds = split(vc[i], ' ');
		cmd = cmds[0][0];

		switch (cmd) {
		case 'a'://增加账户
			type = cmds[1][0];
			id = cmds[2];
			//cin >> type >> id;

			if (type == 's') {
				rate = stold(cmds[3]);
				//cin >> rate;
				account = new SavingsAccount(date, id, rate);
			}
			else {
				credit = stold(cmds[3]);
				rate = stold(cmds[4]);
				fee = fee = stold(cmds[5]);
				//cin >> credit >> rate >> fee;
				account = new CreditAccount(date, id, credit, rate, fee);
			}
			accounts.push_back(account);
			break;
		case 'd'://存入现金
			index = (int)stol(cmds[1]);
			amount = stol(cmds[2]);
			desc = cmds[3];
			//cin >> index >> amount;
			//getline(cin, desc);
			accounts[index]->deposit(date, amount, desc);
			break;
		case 'w'://取出现金
			index = (int)stol(cmds[1]);
			amount = stol(cmds[2]);
			desc = cmds[3];
			/*cin >> index >> amount;
			getline(cin, desc);*/
			accounts[index]->withdraw(date, amount, desc);
			break;
		case 's'://查询各账户信息
			for (size_t i = 0; i < accounts.size(); i++) {
				cout << "[" << i << "] ";
				accounts[i]->show();
				cout << endl;
			}
			break;
		case 'c'://改变日期
			day = (int)stol(cmds[1]);
			if (day < date.getDay())
				cout << "You cannot specify a previous day";
			else if (day > date.getMaxDay())
				cout << "Invalid day";
			else
				date = Date(date.getYear(), date.getMonth(), day);
			break;
		case 'n'://进入下个月
			if (date.getMonth() == 12)
				date = Date(date.getYear() + 1, 1, 1);
			else
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
				(*iter)->settle(date);
			break;
		case 'q'://查询一段时间内的账目
			date1 = Date::read();
			date2 = Date::read();
			Account::query(date1, date2);
			break;
		}

	}
	//for_each(accounts.begin(), accounts.end(), deleter());
	//return 0;


	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;

	do {

		//显示日期和总金额

		cout << setw(16) << setiosflags(ios::left) << date.toString() << "Total: " << Account::getTotal() << "        command> ";
		break;


		char type;

		int index, day;

		double amount, credit, rate, fee;

		string id, desc;

		//Account* account;

		Date date1, date2;



		cin >> cmd;

		switch (cmd) {

		case 'a'://增加账户

			cin >> type >> id;

			if (type == 's') {

				cin >> rate;

				account = new SavingsAccount(date, id, rate);

			}

			else {

				cin >> credit >> rate >> fee;

				account = new CreditAccount(date, id, credit, rate, fee);

			}

			accounts.push_back(account);

			break;

		case 'd'://存入现金

			cin >> index >> amount;

			getline(cin, desc);

			accounts[index]->deposit(date, amount, desc);

			break;

		case 'w'://取出现金

			cin >> index >> amount;

			getline(cin, desc);

			accounts[index]->withdraw(date, amount, desc);

			break;

		case 's'://查询各账户信息

			for (size_t i = 0; i < accounts.size(); i++) {

				cout << "[" << i << "] ";

				accounts[i]->show();

				cout << endl;

			}

			break;

		case 'c'://改变日期

			cin >> day;

			if (day < date.getDay())

				cout << "You cannot specify a previous day";

			else if (day > date.getMaxDay())

				cout << "Invalid day";

			else

				date = Date(date.getYear(), date.getMonth(), day);

			break;

		case 'n'://进入下个月

			if (date.getMonth() == 12)

				date = Date(date.getYear() + 1, 1, 1);

			else

				date = Date(date.getYear(), date.getMonth() + 1, 1);

			for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)

				(*iter)->settle(date);

			break;

		case 'q'://查询一段时间内的账目

			date1 = Date::read();

			date2 = Date::read();

			Account::query(date1, date2);

			break;

		}

	} while (cmd != 'e');





	for_each(accounts.begin(), accounts.end(), deleter());

	return 0;
}