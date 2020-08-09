#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//ternary search
//kada imamo odredjenu funkciju
//i kada zelimo da na segmentu [a,b] nadjemo neko x
//tako da je f(x)<=f(y) za svako y nad segmentom

//ova funkcija je ternary - searchable
//ako postoji K tako da
//za svako x,y tako da A<=x<y<=k f(x) > f(y)
//za svako x,y tako da K<=x<y<=B f(x) < f(b)

int granica = 100;
double ans;
int a,b;

double f(double x)
{
    //neka f-ja
    return 0.0;
}

int f2(int x)
{
    //neka f-ja
    return 0;
}

double tof_doubles(long double a,long double b)
{
    for(int i=0;i<granica;i++)
    {
        long double m1 = (a*2+b)/3.0;
        long double m2 = (a+2*b)/3.0;

        if(f(m1) > f(m2)) a = m1;
        else b = m2;
    }
    return f(a);
}

int tof_ints(int a,int b)
{
    while(b-a > 4)
    {
        int m1 = (a+b)/2;
        int m2 = (a+b)/2 + 1;

        if(f2(m1) > f2(m2)) a =m1;
        else b = m2;
    }

    int ans = 1e9;
    for(int i=a;i<=b;i++)  ans = min(ans,f2(i));
    return ans;
}

//dobro je nekad podeliti i brojeve u blokove pa raditi tof
//po blokovima

int g(int block,int s)
{
    int ans = 1e9;
    for(int i=block*s;i<(block+1)*s && i<=b;i++) ans = min(ans,f2(i));
    return ans;
}

int tof_blocks(int a,int b,int s)
{
    int l =a/s;
    int r = b/s+1;

    while(r-l>4)
    {
        int m1 = (2*l+r)/3;
        int m2 = (l+2*r)/3;

        if(g(m1,s)>=g(m2,s)) l=m1;
        else r = m2;
    }
    int ans = 1e9;
    for(int i=l*s;i<=r*s && i<=b;i++) ans = min(ans,f2(i));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);




    return 0;
}
