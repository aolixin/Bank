#include <windows.h>
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h> // _kbhit(), _getch()
#include <Mmsystem.h>
#include "Account.h"
#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include<iomanip>
#include "utils.h"

#define KEY_DOWN(vKey) ((GetAsyncKeyState(vKey) & 0x8000) ? 1:0)//GetAsyncKeyState函数中的KEY_DOWN
using namespace std;
#define width  56
#define length  35

int cor[width + 1][length + 1] = { 0 };


//光标移动
void gotoXY(int x, int y) //光标移动到(x,y)位置
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两参数分别是指定哪个窗体，具体位置
}

//打印边框
void print_frame()
{
	for (int x = 0; x < width; x++)
	{
		gotoXY(x, 0);
		cor[x][0] = 1;
		printf("-");
		gotoXY(x, length-1);
		cor[x][length - 1] = 1;
		printf("-");
	}
	for (int y = 0; y < length; y++)
	{
		gotoXY(0, y);
		cor[0][y] = 1;
		printf("|");
		gotoXY(width, y);
		cor[width][y] = 1;
		printf("|");
	}
	printf("\n");
}

//初始界面&&设置难度
void initial_interface()
{
	gotoXY(17, 2);
	printf("选择事务(按空格确定)");
	print_frame();
	int x = 29;
	int h[5] = { 6,12,18,24,30 };
	gotoXY(x, h[0]);
	cout << "注册";
	gotoXY(x, h[1]);
	cout << "登录";
	gotoXY(x, h[2]);
	cout << "存钱";
	gotoXY(x, h[3]);
	cout << "取钱";
	gotoXY(x, h[4]);
	cout << "还钱";
	int ht = 0;
	gotoXY(x - 5, h[0]);
	printf(">>>");
	while (1)
	{
		Sleep(20);
		if (_kbhit())
		{
			gotoXY(x - 5, h[ht]);
			printf("   ");
			char order = _getch();
			if (order == 'w' || order == 'W')
			{
				if (ht != 0)
					ht--;
			}
			else if (order == 's' || order == 'S')
			{
				if (ht != 4)
					ht++;
			}
			else if (order == ' ')
			{
				switch (ht)
				{
				case 0: {
					system("cls");
					print_frame();
					gotoXY(x - 20, 14);
					char type; string id; double rate;
					Account* account;
					Date date(2008, 11, 1);
					cout << "请输入类型(s/c),账户,在一行内输入，中间空格" << endl;
					cin >> type >> id;
					if (type == 's') {
						cout << "请输入利率" << endl;
						cin >> rate;
						account = new SavingsAccount(date, id, rate);
					}
					else {
						double credit, fee;
						cout << "请输入欠款额，利率，本金" << endl;
						cin >> credit >> rate >> fee;
						account = new CreditAccount(date, id, credit, rate, fee);
					}
				}break;
				case 1: {
					system("cls");
					print_frame(); 


				}break;
				}
				system("cls");
				return;
			}
			gotoXY(x - 5, h[ht]);
			printf(">>>");
		}
	}
}