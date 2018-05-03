/*
 * Program to find a root of a mathematical equation using-
 * 1) Bisection method
 * 2) Newton-Raphson method
 * 3) Secant method
 */ 
#include <iostream>
#include <cmath>

using namespace std;

double f1(double x)      // x^3-11=0
{
    return x*x*x-11;
}

double df1(double x)     // d(x^3-11)/dx = 3*x*x
{
    return 3*x*x;
}

double f2(double x)
{
    return cos(x)-x*x*x;
}

double df2(double x)
{
    return -sin(x)-3*x*x;
}

void bisection(double low,double high)
{
    cout<<"BISECTION METHOD\n";
    while((high-low)>1e-12)
    {
        double mid=(low+high)/2;
        if(f2(mid)<0)
            low=mid;
        else
            high=mid;
        printf("%.12lf\n",mid);
    }
}

void newton(double initguess)        // Best out of the three
{
    cout<<"\nNEWTONS METHOD\n";
    while(abs(f2(initguess))>1e-12)
    {
        double nextx=initguess-f2(initguess)/df2(initguess);
        printf("%.12lf\n",nextx);
        initguess=nextx;
    }
}

void secant(double guess1,double guess2)
{
    cout<<"\nSECANT METHOD\n";
    while(abs(f2(guess2))>1e-10)
    {
        double x=guess2-f2(guess2)*((guess2-guess1)/(f2(guess2)-f2(guess1)));
        printf("%.12lf\n",x);
        guess2=guess1;
        guess1=x;
    }
}

int main()
{
    double low,high;
    bisection(0,1);
    newton(0.5);
    secant(0,1);
    return 0;
}
