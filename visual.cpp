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

#define KEY_DOWN(vKey) ((GetAsyncKeyState(vKey) & 0x8000) ? 1:0)//GetAsyncKeyState�����е�KEY_DOWN
using namespace std;
#define width  56
#define length  35

int cor[width + 1][length + 1] = { 0 };


//����ƶ�
void gotoXY(int x, int y) //����ƶ���(x,y)λ��
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//�������ֱ���ָ���ĸ����壬����λ��
}

//��ӡ�߿�
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

//��ʼ����&&�����Ѷ�
void initial_interface()
{
	gotoXY(17, 2);
	printf("ѡ������(���ո�ȷ��)");
	print_frame();
	int x = 29;
	int h[5] = { 6,12,18,24,30 };
	gotoXY(x, h[0]);
	cout << "ע��";
	gotoXY(x, h[1]);
	cout << "��¼";
	gotoXY(x, h[2]);
	cout << "��Ǯ";
	gotoXY(x, h[3]);
	cout << "ȡǮ";
	gotoXY(x, h[4]);
	cout << "��Ǯ";
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
					cout << "����������(s/c),�˻�,��һ�������룬�м�ո�" << endl;
					cin >> type >> id;
					if (type == 's') {
						cout << "����������" << endl;
						cin >> rate;
						account = new SavingsAccount(date, id, rate);
					}
					else {
						double credit, fee;
						cout << "������Ƿ�����ʣ�����" << endl;
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