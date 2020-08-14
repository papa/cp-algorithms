#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//perzistentno segmento stablo
//pravimo nove cvorove, samo one koji
//su nam potrebni i njih najvise ima O(log N)
//i cuvamo niz korenova tih novih segmentnih stabala koje smo napravili
//kako bismo znali odakle da krenemo

struct persistentsegtree
{
    struct cvor
    {
        cvor *l,*r;
        int sum;

        cvor(int val) : l(nullptr),r(nullptr),sum(val) {}
        cvor(cvor *l,cvor *r) : l(l),r(r),sum(0)
        {
            if(l) sum+=l->sum;
            if(r) sum+=r->sum;
        }
    };

    cvor* roots[100005];
    int indeks;
    int n;

    persistentsegtree(int n)
    {
        indeks = 1;
        this->n = n;
    }

    cvor* build(int a[],int tl,int tr)
    {
        if(tl==tr) return new cvor(a[tl]);
        int tm = (tl+tr)/2;
        return new cvor(build(a,tl,tm),build(a,tm+1,tr));
    }

    int get_sum(cvor* cv,int tl,int tr,int l,int r)
    {
        if(l > r) return 0;
        if(l==tl && tr==r) return cv->sum;
        int tm = (tl+tr)/2;
        return get_sum(cv->l,tl,tm,l,min(r,tm)) + get_sum(cv->r,tm+1,tr,max(tm+1,l),r);
    }

    cvor* update(cvor* cv,int tl,int tr,int pos,int val)
    {
        if(tl==tr) return new cvor(val);
        int tm =(tl+tr)/2;
        if(pos<=tm) return new cvor(update(cv->l,tl,tm,pos,val),cv->r);
        else return new cvor(cv->l,update(cv->r,tm+1,tr,pos,val));
    }

    void update(int pos,int val)
    {
        indeks++;
        roots[indeks] = update(roots[indeks-1],1,n,pos,val);
    }

    int get_sum(int l,int r,int tt) //u trenutku tt
    {
        return get_sum(roots[tt],1,n,l,r);
    }

};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n;
    cin >> n;
    int a[n+5];
    for(int i=1;i<=n;i++) cin >> a[i];

    persistentsegtree pseg = persistentsegtree(n);
    pseg.roots[1] = pseg.build(a,1,n);

    return 0;
}
