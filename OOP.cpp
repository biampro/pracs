#include <iostream>
using namespace std;
class complex
{
    float x;
    float y;


public:
    complex(){x=0;y=0;}
     friend ostream & operator << (ostream &out, complex &c);
        friend istream & operator >> (istream &in,  complex &c);
    complex(float real , float imaginary)
    {
        x=real;
        y=imaginary;
    }

        complex operator + (complex c)

        {
        complex temp;
        temp.x=x+c.x;
        temp.y=y+c.y;
        return (temp);
        }

        complex operator * (complex c)
        {
            complex temp;
            temp.x=(x*c.x)-(y*c.y);
            temp.y=(x*c.x)+(y*c.y);
            return (temp);

        }

        complex operator - (complex c)

                {
                complex temp;
                temp.x=x-c.x;
                temp.y=y-c.y;
                return (temp);
                }



};
ostream & operator << (ostream &out,  complex &c)
{
    out << c.x;
    out << "+j" << c.y << endl;
    return out;
}
istream & operator >> (istream &in,  complex &c)
{
    cout << "\n Enter Real Part ";
    in >> c.x;
    cout << " Enter Imaginary Part ";
    in >> c.y;
    return in;
}



        int main()
        {
             complex c1,c3,c4,c5,c6;
             cout<<"Enter the first real and imaginary no:";
             cin >> c5;
             cout << "First complex is ";
             cout << c5;
             cout<<"Enter the second real and imaginary no:";
             cin >> c1;
             cout<<"Second complex no is:";
             cout<<c1;

             c3=c1+c5;
             c4=c1*c5;
             c6=c5-c1;
             cout << "Addition :";
             cout << c3 ;
             cout << " Multiply :";
             cout << c4 ;
             cout<<"Subtraction :";
             cout<<c6;


             return 0;

}
/*
 * Enter the first real and imaginary no:
 Enter Real Part 5
 Enter Imaginary Part 4
First complex is 5+j4
Enter the second real and imaginary no:
 Enter Real Part 3
 Enter Imaginary Part 6
Second complex no is:3+j6
Addition :8+j10
 Multiply :-9+j39
Subtraction :2+j-2
 */
