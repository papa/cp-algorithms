#include <bits/stdc++.h>

using namspace std;

int gcd(int a,int b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

int gcd_it(int a,int b)
{
  while(b)
  {
    a%=b;
    swap(a,b);
  }
  return a;
}

int lcm(int a,int b)
{
  return a/gcd(a,b)*b;
}

int gcd_fast(int a,int b)
{
  if(!a || !b) return a|b;
  int shift = __builtin_ctz(a | b);
  a>>=__builtin_ctz(a);
  do
  {
    b>>=__builtin_ctz(b);
    if(a > b) swap(a,b);
    b-=a;
  }while(b);
  return a << shift;
}

int gcd_extended(int a,int b,int &x,int &y)
{
   if(b==0)
   {
     x=1;
     y=0;
     return a;
   }
   int x1,y1;
   int d = gcd_extended(b,a%b,x1,y1);
   x = y1;
   y = x1 - y1*(a/b);
   return d;
}

int gcd_ext_it(int a,int b,int &x,int &y)
{
  x = 1;
  y = 0;
  int x1 = 0,y1=1,a1=a,b1=b;
  while(b1)
  {
    int q = a1/b1;
    tie(x,x1) = make_tuple(x1,x-q*x1);
    tie(y,y1) = make_tuple(y1,y-q*y1);
    tie(a1,b1) = make_tuple(b1,a1-q*b1);
  }
  return a1;
}

int main()
{

}
