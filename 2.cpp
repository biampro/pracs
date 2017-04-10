#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Pixel
{
public:  
  int x,y;  

       void getpixel();  
};

void Pixel::getpixel()
{
   cout<<"Enter the X co-ordinate:";
   cin>>x;
   cout<<"Enter the Y co-ordinate:";
   cin>>y;
}

class Circle:public Pixel
{
   float rad;
   public:
     void getradius();

};


void Circle::getradius()
{
   float d;
   cout<<"Enter the radius of the circle:";
   cin>>rad;
   d=3-2*rad;
   x=0;
   y=rad;

   do
{
     delay(15);
     putpixel(100+x,100+y,BLUE);
     putpixel(100+y,100+x,BLUE);  
     putpixel(100-x,100+y,BLUE);
     putpixel(100+y,100-x,BLUE);
     putpixel(100-x,100-y,BLUE);
     putpixel(100-y,100-x,BLUE);
     putpixel(100+x,100-y,BLUE);
     putpixel(100-y,100+x,BLUE);
     
 if(d<0)
   {
     d=d+4*x+6;
   }
else
{
   d=d+4*(x-y)+10;
   y=y-1;
}
x=x+1;


}while(x<y);


}

int main()
{ 
   Circle c;
   int ch;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
  setbkcolor(RED);
   do
{
   c.getpixel();
   c.getradius();
   cout<<"DO you want to continue?";
   cin>>ch;
    
}while(ch==1);
getch();
closegraph();
return 0;
}

