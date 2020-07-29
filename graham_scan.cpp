#include <bits/stdc++.h>

using namespace std;

//graham scan
//algoritam koji sluzi da za dat skup tacaka
//konstruise konveksni omotac cija su temena tacke iz skupa
//i koji pokriva sve tacke iz tog skupa

//konstruisu se posebno gornji i donji deo omotaca
//koji se kasnije spajaju

struct pt
{
    int x,y;
};

bool cmp(pt a,pt b)
{
    return a.x < b.x || (a.x==b.x && a.y < b.y);
}

int f(pt a,pt b,pt c)
{
    return a.x*b.y + b.x*c.y + c.x*a.y
           -a.y*b.x - b.y*c.x - c.y*a.x;
}

bool cw(pt a,pt b,pt c)
{
    return f(a,b,c) < 0;
}

bool ccw(pt a,pt b, pt c)
{
    return f(a,b,c) > 0;
}

vector<pt> convex_hull(vector<pt>& a)
{
    if(a.size()==1) return a;

    sort(a.begin(),a.end(),cmp);
    pt p1 = a[0];
    pt p2 = a.back();
    vector<pt> up;
    vector<pt> down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1;i<a.size();i++)
    {
        if(i==a.size()-1 || cw(p1,a[i],p2))
        {
            while(up.size() >=2 && !cw(up[up.size()-2],up[up.size()-1],a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if(i==a.size()-1 || ccw(p1,a[i],p2))
        {
            while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    }

    vector<pt> ch;
    for(int i=0;i<up.size();i++) ch.push_back(up[i]);
    for(int i= down.size()-2;i>0;i--) ch.push_back(down[i]);
    return ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);



    return 0;
}
