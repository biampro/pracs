#include<graphics.h>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
int i,xmid,ymid,x1,y1,x2,y2,x3,y3,x,y,dy,dx,p,gap=50,temp1,temp2,temp3,option,xc,yc,a;
int x1dash,x2dash,x3dash,y1dash,y2dash,y3dash;
double theta;
float m;
char ans;

do{

cleardevice();
cout<<"Enter first co-ords of the triangle\n";
cin>>x1>>y1;
cout<<"Enter second co-ords of the triangle\n";
cin>>x2>>y2;
cout<<"Enter third co-ords of the triangle\n";
cin>>x3>>y3;

xmid= getmaxx()/2;
ymid= getmaxy()/2;
line(0,ymid,getmaxx(),ymid);
line(xmid,0,xmid,getmaxy());
line(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
line(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
line(x3+xmid,ymid-y3,x1+xmid,ymid-y1);

setcolor(255);
cout<<"Reflection about \n";
cout<<"X axis :  1\n";
cout<<"Y axis : 2\n";
cout<<"X=Y axis : 3\n";
cout<<"X=Y axis : 4\n";
cout<<" Enter the option (1-4):";
cin>>option;
switch( option)
{
case 1:  y1=-y1; y2=-y2;y3=-y3; break;

case 2:  x1=-x1;x2=-x2;x3=-x3;break;

case 3:  temp1=x1;temp2=x2;temp3=x3;
	x1=y1;x2=y2;x3=y3;
	y1=temp1;y2=temp2;y3=temp3;

case 4:cout<<"rotation about arbitrary point";
	cin>>xc>>yc;
	cout<<"angle";
	cin>>a;
	a = (a*3.14)/180.0;

	cout<<"Translating";
	x1=x1-xc;x2=x2-xc;x3=x3-xc;
	y1=y1-yc;y2=y2-yc;y3=y3-yc;
cout<<"Rotating";
        x1=(x1*cos(a))-(y1*sin(a));
	y1=(x1*sin(a))+(y1*cos(a));
	x2=(x2*cos(a))-(y2*sin(a));
	y2=(x2*sin(a))+(y2*cos(a));
	x3=(x3*cos(a))-(y3*sin(a));
	y3=(x3*sin(a))+(y3*cos(a));
cout<<"Translating";

        x1=x1+xc;x2=x2+xc;x3=x3+xc;
	y1=y1+yc;y2=y2+yc;y3=y3+yc;


	break;
}
line(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
line(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
line(x3+xmid,ymid-y3,x1+xmid,ymid-y1);
cout<<"Do you want to continue : ";
cin>>ans;
}while(ans=='y');
closegraph();
return 0;
}



//




