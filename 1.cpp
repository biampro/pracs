#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixel
{
public:
	int x1,y1,x2,y2;
	void getpixel()
	{
	cout<<"Enter the First co-ordinate";
	cin>>x1>>y1;
	cout<<"\nEnter the Second co-ordinate";
	cin>>x2>>y2;	
	}
};
class dda_bre:public pixel
{
public:
	int x,y,dx,dy,steps,temp;
	float xinc,yinc;
	void drawline();//draw line using dda
	void drawline(int,int);//draw line using bresenhams
	
};
void dda_bre::drawline()
{
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>dy)
steps=dx;
else
steps=dy;
xinc=dx/steps;
yinc=dy/steps;
x=x1;
y=y1;
for(int i=0;i<steps;i++)
{
putpixel(x,y,WHITE);
delay(10);
x=x+xinc;
y=y+yinc;
}
}

void dda_bre::drawline(int x,int y)
{
float m,p;
dx=abs(x2-x1);
dy=abs(y2-y1);
p=2*dy-dx;
m=dy/dx;
x=x1;
y=y1;
if(m>1)
{
temp=x;
x=y;
y=temp;
}
for(int i=0;i<dx;i++)
{
putpixel(x,y,20);
delay(10);
x++;
if(p>0)
{
y++;
p=p+2*dy-2*dx;
}
else
{
p=p+2*dy;
}
}
}
int main()
{
dda_bre db;
int ch,ans;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
do
{
cout<<"\n\n---------MENU---------\n\t1.DDA LINE\n\t2.BRESENHAM'S LINE\n\t3.EXIT\nEnter your choice";
cin>>ch;
switch(ch)
{
case 1:
	db.getpixel();
	db.drawline();
	break;
case 2:
	db.getpixel();
	db.drawline(0,0);
	break;
case 3:
	break;	
default:
	cout<<"Enter valid choice";
	break;
}
cout<<"Do you want to continue?<1/0>";
cin>>ans;
}while(ans==1);
getch();
closegraph();
exit(0);
return 0;
}
