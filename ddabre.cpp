#include<iostream>
using namespace std;
#include<cmath>
#include<graphics.h>

class pixel
{
protected:
int x1,y1,x2,y2;
public:
void getpixel();
};
void pixel :: getpixel()
{
cout<<"Enter x1:";
cin>>x1;
cout<<"Enter y1:";
cin>>y1;
cout<<"Enter x2:";
cin>>x2;
cout<<"Enter y2:";
cin>>y2;
}


class ddabre : public pixel
{
protected:
int steps,g,x,y,dx,dy,xinc,yinc,temp,m;

public:
void drawdda();
void drawbre(int x, int y);
};

void ddabre:: drawdda()
{
dx=(x2-x1);
dy=(y2-y1);
if (dx>dy)
steps=dx;
else
steps=dy;

x=x1;
y=y1;

xinc=dx/steps;
yinc=dy/steps;

for(int i=0;i<steps;i++)
  {
    putpixel(x,y,WHITE);
    delay(100);
    x=x+xinc;
    y=y+yinc;
  
  }






}

void ddabre :: drawbre(int x , int y)
{
dx=(x2-x1);
dy=(y2-y1);
g=(2*dy)-dx;
x=x1;
y=y1;
m=dy/dx;
if(m>1)
{
x=temp;
x=y;
y=temp;;

}
for(int i=0;i<dx;i++)
{
putpixel(x,y,RED);
delay(100);
x++;
}

if (g>0)
{
y++;
g=g+(2*dy)-(2*dx);

}
else
g=g+(2*dy);
}

int main()
{
int choice; 
char ans;
ddabre db;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
do
{
cout<<"\n \n MENU:";
cout<<"\n \n 1.DDA Line \n Bresnhams Line ";
cout<<"Enter Your Choice";
cin>>choice;
switch (choice)
{
case 1: 
db.getpixel();
db.drawdda();
break;

case 2:
db.getpixel();
db.drawbre(0,0);
break;
default:
cout<<"Sahi Daalna";
break;
}
cout<<"Do you want to continue:";
cin>>ans;
}
while(ans=='y'|| ans == 'Y');
closegraph();
return 0;

}




