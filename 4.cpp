#include<iostream>
#include<cmath>
#include<graphics.h>
#include<string.h>
using namespace std;

class transformation {
private:
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    void getcordinates1();
    void getcordinates2();
public:
    void ddaline(int,int,int,int);
    void translation();
    void scaling();
    void rotation();
};

void transformation :: ddaline(int x1,int y1,int x2,int y2)
{
    int dx,dy,steps,xinc,yinc;
    int i;
    int x,y;

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

    for(i=0;i<steps;i++)
    {
            putpixel(x,y,RED);
            x = x + xinc;
            y = y + yinc;
    }
}

void transformation :: getcordinates1()
{
    cout<<"\nEnter x1 and y1 coordinates for first point ";
    cin>>x1>>y1;
    cout<<"\nEnter x2 and y2 coordinates for second point ";
    cin>>x2>>y2;
}

void transformation :: getcordinates2()
{

    cout<<"\nEnter x1 and y1 cordinates for first point ";
    cin>>x1>>y1;
    cout<<"\nEnter x2 and y2 cordinates for second point ";
    cin>>x2>>y2;
    cout<<"\nEnter x3 and y3 cordinates for third point ";
    cin>>x3>>y3;
    cout<<"\nEnter x4 and y4 cordinates for fourth point ";
    cin>>x4>>y4;
}








void transformation :: translation()
{
    int tx,ty;

    getcordinates1();
    cleardevice();
    ddaline(x1,y1,x2,y2);

    cout<<"\nEnter translation factor for X-axis ";
    cin>>tx;
    cout<<"\nEnter translation factor for Y-axis ";
    cin>>ty;

    x_1 = x1 + tx;
    y_1 = y1 + ty;
    x_2 = x2 + tx;
    y_2 = y2 + ty;
    delay(1500);
    cleardevice();
    ddaline(x_1,y_1,x_2,y_2);
}



void transformation :: scaling()
{
    int Sx,Sy;
    
    getcordinates2();
    cleardevice();
    ddaline(x1,y1,x2,y2);
    ddaline(x2,y2,x3,y3);
    ddaline(x4,y4,x3,y3);
    ddaline(x1,y1,x4,y4);

    
    cout<<"\nEnter Scaling factor Sx ";
    cin>>Sx;
    cout<<"\nEnter Scaling factor Sy ";
    cin>>Sy;

    x_1=x1*Sx;x_2=x2*Sx;x_3=x3*Sx;x_4=x4*Sx;
    y_1=y1*Sy;y_2=y2*Sy;y_3=y3*Sy;y_4=y4*Sy;
    

    delay(1500);
    cleardevice();
    ddaline(x_1,y_1,x_2,y_2);
    ddaline(x_2,y_2,x_3,y_3);
    ddaline(x_4,y_4,x_3,y_3);
    ddaline(x_1,y_1,x_4,y_4);
}

void transformation :: rotation()
{
    int angle;

    getcordinates1();
    cleardevice();
    ddaline(x1,y1,x2,y2);

    cout<<"\nEnter the rotation angle ";
    cin>>angle;

    angle = (angle*3.14)/180.0;
    x_1 = x1;
    y_1 = y1;
    x_2 = x1 + ((x2 - x1)*cos(angle) - (y2 - y1)*sin(angle));
    y_2 = y1 + ((x2 - x1)*sin(angle) + (y2 - y1)*cos(angle));

    delay(20000);
    cleardevice();
    ddaline(x_1,y_1,x_2,y_2);
}




int main()
{
    int ch;
    int gd = DETECT,gm;
        initgraph(&gd,&gm,NULL);

    transformation tr;
    do
    {
        cout<<"\n------2-D Transformation------";
        cout<<"\n1.Translation";
        cout<<"\n2.Scaling";
        cout<<"\n3.Rotation";
	cout<<"\n4.Exit";
        cout<<"\nEnter your choice ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            tr.translation();
            break;
        case 2:
            tr.scaling();
            break;
        case 3:
            tr.rotation();
	    break;
	case 4:
            break;
        default :
            cout<<"\nWrong choice";
        }//switch
    }while(ch != 3);

    return 0;
};


















