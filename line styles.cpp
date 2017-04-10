#include<iostream>
#include<graphics.h>
using namespace std;

class Lines
{
	int x1,y1,x2,y2,x,y;
	int xinc,yinc,steps,dx,dy;
	void getcoordinates();
	void line();
public:
	void Thick();
	void Dotted();
	void Dashed();
	void DashedDotted();
};

void Lines :: getcoordinates()
{
	cout<<"\nEnter the coordinates for x1 and y1 ";
	cin>>x1>>y1;
	cout<<"\nEnter the coordinates for x2 and y2 ";
	cin>>x2>>y2;
}

void Lines :: line()
{
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy)
		steps = dx;
	else
		steps = dy;

	x = x1;
	y = y1;

	xinc = dx/steps;
	yinc = dy/steps;
}

void Lines :: Thick()
{
	int w,i,j;

	cout<<"\nEnter the coordinates for thick line";
	getcoordinates();
	cout<<"\nEnter the width of the line ";
	cin>>w;

	line();
	cleardevice();

	for(i=0;i<steps;i++)
	{
		x = x + xinc;
		y = y + yinc;
	
		for(j=0;j<w;j++)
			putpixel(x+j,y,RED);
		delay(25);
}
}

void Lines :: Dashed()
{
	int i;
	cout<<"\nEnter the coordinates for dashed lines";
	getcoordinates();

	line();
	cleardevice();

	for(i=0;i<steps;i++)
	{
		x = x + xinc;
		y = y + yinc;
	
		if(i%10 == 1 || i%10 == 2 || i%10 == 3 || i%10 == 4 || i%10 == 5)
		{
			putpixel(x,y,RED);
			delay(25);
		}
	}
}

void Lines :: Dotted()
	{
	int i;

	cout<<"\nEnter the coordinates for dotted lines";
	getcoordinates();

	line();
	cleardevice();

	for(i=0;i<steps;i++)
	{
		x = x + xinc;
		y = y + yinc;

		if(i%2 == 0 && i%3==0 && i%4==0)
			putpixel(x,y,RED);
		delay(25);
	}
}

void Lines :: DashedDotted()
{
	int i;

	cout<<"\nEnter the coordinates for dashed-dotted line";
	getcoordinates();

	line();
	cleardevice();

	for(i=0;i<steps;i++)
	{
		x = x + xinc;
		y = y + yinc;

		//if(i%20 == 1 || i%20 == 2 || i%20 == 3 || i%20 == 4 || i%20 == 5 || i%20 ==6 || i%20 == 7 || i%20 == 8 || i%20 == 9 || i%20 == 10 || i%20 == 15 || i%20 == 16)
		if((i%20 > 0 && i%20 < 11) || i%20 == 15 || i%20 == 16)
		{
			putpixel(x,y,RED);
			delay(25);
		}
	}
}

int main()
{
	int ch;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	Lines l;

	do
	{
		cout<<"\nWhich type of line do you want";
		cout<<"\n1.Thick";
		cout<<"\n2.Dotted";
		cout<<"\n3.Dashed";
		cout<<"\n4.Dashed-Dotted";
		cout<<"\n5.Exit";
		cout<<"\nEnter your choice ";
		cin>>ch;

		switch(ch)
		{
			case 1:
			l.Thick();
			break;
			case 2:
			l.Dotted();
			break;
			case 3:
			l.Dashed();
			break;
			case 4:
			l.DashedDotted();
			break;
			case 5:
			break;
			default:
			cout<<"\nWrong choice";
		}//switch
	}while(ch != 5);
	return 0;
}﻿
