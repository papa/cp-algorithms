#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//nearset pair of points

//zadatak je naci par tacaka tako da je
//izmedju njih najmanja distanca

//naivni algoritam je da prodjemo po svim parovima
//i tako samo nadjemo najbolji O(n^2)

//sortiramo tacke po x pa po y koordinatama
//i onda koristimo princip divide and conquer
//kako bismo nasli resenje
//kada nadjemo resenje za 2 polovine pitanje je kako da ukombinujemo
//poenta je u tome sto kada imamo neku tacku p potrebno je pogledati
//najvise 8 drugih tacaka kako bismo nasli resenje

struct pt
{
    int x,y,id;
};

struct cmp_x
{
    bool operator () (const pt & a,const pt & b)
    {
        return a.x < b.x || (a.x==b.x && a.y < b.y);
    }
};

struct cmp_y
{
    bool operator () (const pt & a,const pt & b)
    {
        return a.y < b.y;
    }
};

double mindist;
pair<int,int> best_pair;
vector<pt> t;
vector<pt> a;
int n;

void upd_ans(const pt & a,const pt & b)
{
    double dist=sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if(dist < mindist)
    {
        mindist = dist;
        best_pair = {a.id,b.id};
    }
}

void rec(int l,int r)
{
    if(r-l<=3)
    {
        for(int i=l;i<r;i++)
            for(int j =i+1;j<r;j++) upd_ans(a[i],a[j]);

        sort(a.begin()+l,a.begin()+r,cmp_y());
        return;
    }

    int m = (l+r) >> 1;
    int midx = a[m].x;
    rec(l,m);
    rec(m,r);

    merge(a.begin()+l,a.begin()+m,a.begin()+m,a.begin()+r,t.begin(),cmp_y());
    copy(t.begin(),t.begin()+r-l,a.begin()+l);

    int tsz = 0;
    for(int i=l;i<r;i++)
    {
        if(abs(a[i].x-midx) < mindist)
        {
            for(int j =tsz-1;j>=0 && a[i].y-t[j].y<mindist;j--)
                upd_ans(a[i],t[j]);

            t[tsz++] = a[i];
        }
    }
}

void solve()
{
    t.resize(n);
    sort(a.begin(),a.end(),cmp_x());
    mindist = (double)1e18;
    rec(0,n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);

	return 0;
}
