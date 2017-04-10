#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class dda
{
public:
	int x,y,dx,dy,steps,temp;
	float xinc,yinc;
	void drawline(int,int,int,int);
	
};
void dda::drawline(int x1,int y1,int x2,int y2)
{
dx=x2-x1;
dy=y2-y1;
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
delay(5);
x=x+xinc;
y=y+yinc;
}
}

int main()
{
int gdrive=DETECT,gmode,i;
initgraph(&gdrive,&gmode,NULL);
dda obj;
int x1,y1,x2,y2;
float p1,q1,p2,q2,p3,q3,p4,q4;
float a1,b1,a2,b2,a3,b3,a4,b4;
cout<<"enter x1 : ";
cin>>x1;
cout<<"enter y1 : ";
cin>>y1;
cout<<"enter x2 : ";
cin>>x2;
cout<<"enter y2 : ";
cin>>y2;

//rectangle
    obj.drawline(x1,y1,x2,y1);
    obj.drawline(x2,y1,x2,y2);
    obj.drawline(x1,y2,x2,y2);
    obj.drawline(x1,y1,x1,y2);

//rhombus
	p1=(x1+x2)/2;
	q1=(y1+y1)/2;

	p2=(x2+x2)/2;
	q2=(y1+y2)/2;
	
	p3=(x2+x1)/2;
	q3=(y2+y2)/2;
	
	p4=(x1+x1)/2;
	q4=(y2+y1)/2;

	obj.drawline(p1,q1,p2,q2);
	obj.drawline(p2,q2,p3,q3);
	obj.drawline(p4,q4,p3,q3);
	obj.drawline(p4,q4,p1,q1);

//rectangle

	a1=(p1+p2)/2;
	b1=(q1+q2)/2;

	a2=(p2+p3)/2;
	b2=(q2+q3)/2;
	
	a3=(p3+p4)/2;
	b3=(q3+q4)/2;
	
	a4=(p4+p1)/2;
	b4=(q4+q1)/2;

	obj.drawline(a1,b1,a2,b2);
	obj.drawline(a3,b3,a2,b2);
	obj.drawline(a4,b4,a3,b3);
	obj.drawline(a4,b4,a1,b1);
	getchar();
	closegraph();
return 0;
}

