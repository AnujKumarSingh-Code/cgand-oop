#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std ;
#define    int long long 
#define    FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define    TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define    rep(i,n) for (int i = 0; i < (n); ++i)
#define    all(x) (x).begin(), (x).end()
#define    nl "\n"
const   int INF = 1e18 ;
#define PI 3.14159265

class Complex
{
    private:
        float real , img;
    
    public:

        Complex()
        {
            real = 0.0f , img = 0.0f;
        }

        Complex(float a , float b)
        {
            real = a, img = b;
        }

        Complex operator + (Complex &c1)
        {
            Complex temp;
            temp.real = real + c1.real;
            temp.img = img + c1.img;

            return temp;
        }

        Complex operator - (Complex &c1)
        {
            Complex temp;
            temp.real = real - c1.real;
            temp.img = img - c1.img;

            return temp;
        }

        Complex operator * (Complex &c)
        {
            Complex temp;
            temp.real = real*c.real - img*c.img;
            temp.img = real*c.img + img*c.real;

            return temp;
        }

        Complex operator / (Complex &c)
        {
            Complex temp;
            temp.real = (real*c.real - img*c.img)/(c.real*c.real + c.img*c.img);
            temp.img = (real*c.img + img*c.real)/(c.real*c.real + c.img*c.img);

            return temp;
        }


        friend ostream &operator << (ostream &out , Complex &c)
        {
            out<<c.real<<"+"<<c.img<<"i"<<nl;
            return out;
        }

        friend istream &operator >> (istream &in , Complex &c)
        {
            in>>c.real>>c.img;
            return in;
        }
};

signed main()
{
    Complex c1 , c2 , c3;
    cout<<"enter the first cpmlex noi : "<<nl;
    cin>>c1;

    cout<<"enter the second cpmlex noi : "<<nl;
    cin>>c2;
    cout<<"sum is : ";
    c3 = c1 + c2;
    cout<<c3<<nl;
    cout<<nl;

    cout<<"subs is"<<nl;
    c3 = c1 - c2;


    cout<<c3<<nl;

    cout<<"multipl is : "<<nl;
    c3 = c1 * c2;
    cout<<c3<<nl;

    cout<<"didvide i : "<<nl;
    c3 = c1/c2;
    cout<<c3<<nl;

}