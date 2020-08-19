#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt
{
   ll x,y;
   pt(){}
   pt(ll x_,ll y_):x(x_),y(y_){}
   pt operator+(const pt & p) const {return pt(x+p.x,y+p.y);}
   pt operator-(const pt & p) const {return pt(x-p.x,y-p.y);}
   ll cross(const pt & p) const {return x*p.y - y*p.x;}
   ll dot(const pt & p) const {return x*p.x + y*p.y;}
   ll cross(const pt & a,const pt & b) const {return (a-*this).cross(b-*this);}
   ll dot(const pt & a,const pt & b) const {return (a-*this).dot(b-*this);}
   ll sqrLen() const {return this->dot(*this);}
};

bool cmp(const pt & a,const pt & b)
{
    return a.x < b.x || (a.x==b.x && a.y < b.y);
}

int sgn(ll val)
{
    return (val > 0) ? 1 : (val==0 ? 0 : -1);
}

vector<pt> v;
int n;
vector<pt> pts;
int m;

bool pointInTriangle(pt a,pt b,pt c,pt point,int pos)
{
    ll s1 = abs(a.cross(b,c));
    //ova 4 uslova su da izbacimo pripadanje tacke
    //granici poligona
    if(abs(point.cross(a,b)) == 0LL) return false; //1
    if(pos==n-1 && abs(point.cross(a,b))==0LL) return false; //2
    if(pos==n-2 && abs(point.cross(b,c))==0LL) return false; //3
    if(pos==0 && abs(point.cross(c,a))==0LL) return false; // 4
    ll s2 = abs(point.cross(a,b)) + abs(point.cross(b,c)) + abs(point.cross(c,a));
    return (s1==s2);
}

void prepare(vector<pt> & points)
{
    n = points.size();
    int pos = 0;
    for(int i=1;i<n;i++)
        if(cmp(points[i],points[pos])) pos = i;
    rotate(points.begin(),points.begin() + pos,points.end());
    n--;
    v.resize(n);
    for(int i=0;i<n;i++) v[i] = points[i+1] - points[0];
}

bool pointInPolygon(pt point)
{
    point = point - pts[0];
    if(v[0].cross(point)!=0 && sgn(v[0].cross(point)) != sgn(v[0].cross(v[n-1]))) return false;
    if(v[n-1].cross(point)!=0 && sgn(v[n-1].cross(point))!=sgn(v[n-1].cross(v[0]))) return false;
    
    if(v[0].cross(point)==0) return false; //ovo menjamo u v[0].sqrLen() >= point.sqrLen(); 
    //ako hocemo da tacka pripada granici poligona

    int l = 0;
    int r = n-1;
    while(r-l > 1)
    {
        int mid = (l+r) >> 1;
        int pos = mid;
        if(v[pos].cross(point)>=0) l = mid;
        else r = mid;
    }
    int pos = l;
    return pointInTriangle(v[pos],v[pos+1],pt(0,0),point, pos);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    return 0;
}