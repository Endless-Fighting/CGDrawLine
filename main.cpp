/*
二维题目 - 2
在屏幕上生成一个600×400的网格，然后利用bresenham画线算法，在该网格范围内实现任意直线段的绘制。
要求：
	绘制的直线段坐标不超出网格范围；
	以随机的方式生成直线的两个端点的坐标，每次绘制的直线条数不少于10条；
	设置定时器，使得填充计算每隔一小段时间计算一次，实现动画效果；
*/

#include <iostream>
#include <graphics.h>  
#include<conio.h>
#include <time.h>

using namespace std;

#define WIDTH 600
#define HEIGHT 400

//使用Bresenham画线算法根据两端点画线
void drawLine(int x0, int y0, int x1, int y1)
{
	int x = x0, y = y0;
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int incrementX, incrementY;	//XY增量
	bool interchange;	//是否交换步长方向
	int p;	//2·Δy-Δx

			//根据线段方向确定增量正负
	if (x1>x0)
		incrementX = 1;
	else
		incrementX = -1;

	if (y1>y0)
		incrementY = 1;
	else
		incrementY = -1;

	//根据Δy、Δx大小确定步长方向
	if (dy>dx)
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		interchange = true;
	}
	else
		interchange = false;

	//循环实现直线的生成
	p = 2 * dy - dx;
	for (int i = 1; i <= dx; i++)
	{
		Sleep(1);
		putpixel(x, y, WHITE);
		if (p >= 0)
		{
			if (interchange == false)
				y = y + incrementY;
			else
				x = x + incrementX;
			p = p - 2 * dx;
		}
		if (interchange == false)
			x = x + incrementX;
		else
			y = y + incrementY;
		p = p + 2 * dy;
	}
}

void drawLines()
{
	cleardevice();
	outtextxy(120, 350, _T("全部直线输出完成后，按任意键清屏进行下一轮输出"));
	int numOfLines = rand() % 5 + 10;

	for (int i = 0; i < numOfLines; i++)
	{
		drawLine(rand() % WIDTH, rand() % HEIGHT, rand() % WIDTH, rand() % HEIGHT);
	}
}

int main()
{
	initgraph(WIDTH, HEIGHT);
	srand((unsigned)time(NULL));

	do
	{
		drawLines();
	} while (_getch());

	closegraph();
	return 0;
}
