#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//implicitno segmentno stablo

struct cvor
{
    int le,ri;
    int sum = 0;
    cvor *l = nullptr;
    cvor *r = nullptr;

    cvor(int lb,int rb)
    {
        le = lb;
        ri = rb;
    }

    void extend()
    {
        if(!l && le + 1 < ri)
        {
            int t=(le+ri)/2;
            l = new cvor(le,t);
            r = new cvor(t+1,ri);//ili (t,ri)
        }
    }

    void add(int k,int x)
    {
        extend();
        sum+=x;
        if(l)
        {
            if(k < l->ri) l->add(k,x);
            else r->add(k,x);
        }
    }

    int getsum(int lq,int rq)
    {
        if(lq<=le && ri<=rq)
            return sum;
        if(max(le,lq) >= min(ri,rq)) return 0;
        extend();
        return l->getsum(lq,rq) + r->getsum(lq,rq);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);



    return 0;
}
