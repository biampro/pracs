#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;
class pixel
{
protected:
	int x1,y1,x2,y2;
public:
	void getpixel();
};
void pixel :: getpixel()
{
	cout<<"\n Please enter x1: ";
	cin>>x1;
	cout<<"\n Please enter y1: ";
	cin>>y1;
	cout<<"\n Please enter x2: ";
	cin>>x2;
	cout<<"\n Please enter y2: ";
	cin>>y2;
}



class DDA_BRE : public pixel
{
protected:
	float x,y,dx,dy,xinc,yinc,g,temp,m;
	int steps,i;
public:
	void drawline();
	void dotted();
	void dashed();
	void dash_dot();
	void thick();
};
void DDA_BRE :: thick()
{

	int w;
	cout<<"Enter Width of line : ";
	cin>>w;

	for(int j=0;j<w;j++)
	{
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		if(dx>dy)
		steps=dx;
		else
		steps=dy;
		x=x1;
		y=y1;
		xinc=dx/steps;
		yinc=dy/steps;
		for(i=0;i<steps;i++)
		{
		putpixel(x,y,WHITE);
		delay(10);
		x=x+xinc;
		y=y+yinc;
		}

		x1++;
		x2++;
	}

	
}
void DDA_BRE :: dash_dot()
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	x=x1;
	y=y1;
	xinc=dx/steps;
	yinc=dy/steps;
	for(i=0;i<steps;i++)
	{
	if(i%10==0||i%10==2||i%10==3||i%10==4||i%10==1||i%10==7)
	putpixel(x,y,WHITE);


	delay(10);
	x=x+xinc;
	y=y+yinc;

	}



}
void DDA_BRE :: dashed()
{

	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	x=x1;
	y=y1;
	xinc=dx/steps;
	yinc=dy/steps;
	for(i=0;i<steps;i++)
	{	
		if(i%10==0||i%10==2||i%10==3||i%10==4||i%10==1){
		putpixel(x,y,WHITE);
		
		}
				
		delay(10);
		x=x+xinc;
		y=y+yinc;

	}


}
void DDA_BRE :: dotted()
{
	int k=0;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	x=x1;
	y=y1;
	xinc=dx/steps;
	yinc=dy/steps;
	for(i=0;i<steps;i++)
	{k=i%2;
	if(k==0)
	putpixel(x,y,WHITE);
	delay(10);
	x=x+xinc;
	y=y+yinc;

	}


}
void DDA_BRE :: drawline()
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	x=x1;
	y=y1;
	xinc=dx/steps;
	yinc=dy/steps;
	for(i=0;i<steps;i++)
	{
	putpixel(x,y,WHITE);
	delay(10);
	x=x+xinc;
	y=y+yinc;

	}
}
int main()
{
	DDA_BRE obj;
	int gd=DETECT,gm;
	int choice;
	char ans;
		initgraph(&gd,&gm,NULL);
	do{
		obj.getpixel();
		cout<<"1) Thin\n2) Dotted\n3) Dashed\n4) Thick\n5) Dashed dotted\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{ 		
		case 1:cleardevice();
			obj.drawline();
			break;
		case 2:cleardevice();
			obj.dotted();
			break;
		case 3:cleardevice();
			obj.dashed();
			break;
		case 4:cleardevice();
			obj.thick();
			break;
		case 5:cleardevice();
			obj.dash_dot();
			break;

		}
		cout<<"Do you want to continue : ";
		cin>>ans;
		
	}while(ans=='y');
	return 0;
}


