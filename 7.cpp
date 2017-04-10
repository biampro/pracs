#include<iostream>
#include<graphics.h>
using namespace std;

class Polygon
{
        int x[20],y[20];
        int ver;
        void display();
        void Flood_fill(int ,int ,int );
public:
        Polygon(int );
        void create();
};

Polygon :: Polygon(int n1)
{
        int i;
        ver = n1;
      
        for(i=0;i<ver;i++)
                x[i] = y[i] = 0;
}

void Polygon :: create()
{
        int i;

        for(i=0;i<ver;i++)
        {
                cout<<"\nEnter coordinate "<<i+1<<" for x ";
                cin>>x[i];
                cout<<"\nEnter coordinate "<<i+1<<" for y ";
                cin>>y[i];
        }

        display();
}

void Polygon :: display()
{
        int i,sum1,sum2;
        int x1,y1;
        sum1 = sum2 = 0;

        for(i=0;i<ver-1;i++)
                line(x[i],y[i],x[i+1],y[i+1]);
        for(i=0;i<1;i++)
                line(x[0],y[0],x[ver-1],y[ver-1]);
       
        for(i=0;i<ver;i++)
        {
                sum1 = sum1 + x[i];
                sum2 = sum2 + y[i];
        }

        x1 = sum1/ver;
        y1 = sum2/ver;

        Flood_fill(x1,y1,15);
}

void Polygon :: Flood_fill(int x2,int y2,int newcolor)
{
        int current;

        current = getpixel(x2,y2);

        delay(1);
        if(current != newcolor)
        {
                putpixel(x2,y2,newcolor);
                Flood_fill(x2+1,y2,newcolor);
                Flood_fill(x2,y2+1,newcolor);
                Flood_fill(x2-1,y2,newcolor);
                Flood_fill(x2,y2-1,newcolor);
               
        }
}

int main()
{
        int gd = DETECT,gm;
        initgraph(&gd,&gm,NULL);
        int n,ch;

        cout<<"\nEnter the total number of vertices for a convex polygon ";
        cin>>n;
        Polygon pl(n);
        pl.create();
               
        getch();
        return 0;
}
