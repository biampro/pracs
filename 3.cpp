#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define MAX 100


class transform
{
  private : int x[MAX],y[MAX],edges;

  public : void accept();
	   void draw(int x[MAX],int y[MAX]);
	   void scanline(int x[MAX],int y[MAX],int edges);

};

void transform :: accept()
{
	int i,j;
	cout<<"Enter no of edges : ";
	cin>>edges;
	cout<<"Enter co-ordinate in matrix form\n";
	for(i=0;i<edges;i++)
	 {
		 cout<<"\nx = ";
		 cin>>x[i];
		 cout<<"y = ";
		 cin>>y[i];
	 }
	 draw(x,y);
	 scanline(x,y,edges);
}


			//draw a line
void transform :: draw(int x[MAX],int y[MAX])
{
 int i;

 for(i=0;i<edges-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	 line(x[i],y[i],x[0],y[0]);
}





void transform :: scanline(int x[MAX],int y[MAX],int edges)
{
 int i,k,int_x[50],temp,yco,ymax=0,ymin=720,xmax=0,xmin=480;
 int ycn,xcn,cnt,xy[MAX][MAX],clr,xc[MAX],yc[MAX];

 float m[50],dx,dy;

	for (i=0;i<edges;i++)
		 {
			 if(y[i]>=ymax)
				 ymax=y[i];
			 if(y[i]<=ymin)
				ymin=y[i];
			 if(x[i]>=xmax)
				 xmax=x[i];
			 if(x[i]<=xmin)
				xmin=x[i];
}


cout<<"\nymax "<<ymax;
cout<<"\nymin "<<ymin;
cout<<"\nxmax "<<xmax;
cout<<"\nxmin "<<xmin;
setcolor(4);

line(xmin,ymin,xmax,ymin);
line(xmax,ymin,xmax,ymax);
line(xmax,ymax,xmin,ymax);
line(xmin,ymax,xmin,ymin);

int p=0;
for(int k1=ymin;k1<=ymax;k1++)
{
	for(int l=xmin;l<=xmax;l++)
	 {
	    clr=getpixel(l,k1);
	    if(clr==15)
	     {
	       xc[p]=l;
	       yc[p]=k1;
	       p++;
	    }
	 }
	 p=0;
	 setcolor(10);
	 line(xc[p],yc[p],xc[p+1],yc[p+1]);
}

}

int main()
{
 char ch;
 int gd=DETECT,gm,i;
 int cho;
 transform t;

 do
  {
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    cleardevice();
    cout<<"\n----MENU----\n1) ACCEPT EDGES\n";

    cout<<"\nEnter your choice : ";
    cin>>cho;
    switch(cho)
     {
      case 1 : t.accept();
	       break;

      case 7 : exit(0);

      default :cout<<"WRONG CHOICE";
     }
     cout<<"\n\tDO U WANT CONTINUE (y/n) : ";
     cin>>ch;
   }while(ch=='y' || ch=='Y');
 return(0);
}