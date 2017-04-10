#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;

class pixel
{
protected:
int x,y;
public:
void getpixel();
};

void pixel :: getpixel()
{
cout<<"Enter x1:";
cin>>x;
cout<<"Enter y1:";
cin>>y;
}
 
class bc : public pixel
{
public:
float radius;
void drawcircle();
};

void bc :: drawcircle ()
{
float d;
cout<<"Enter Radius of Circle:";
cin>>radius;
d=3-2*radius;
x=0;	
y=radius;

do
{

	putpixel(200+x,200+y,RED);
	putpixel(200+y,200+x,RED);
	putpixel(200+x,200-y,RED);
	putpixel(200-y,200+x,RED);
	putpixel(200-x,200-y,RED);
	putpixel(200-y,200-x,RED);
	putpixel(200-x,200+y,RED);
	putpixel(200+y,200-x,RED);

if (d<0)
	{d=d+(4*x)+6;}
else
	{d=d+(4*(x-y))+10;
 	y=y-1;}
x=x+1;
}while(x<y);

}

int main()
{
 int gd= DETECT,gm;
 initgraph(&gd,&gm,NULL);
 bc db;
 db.getpixel();
 db.drawcircle();
	getch();
return 0; 	
 }


