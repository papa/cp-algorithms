#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Heavy light decomposition
//struktura koja nam pomaze da odgovorimo
//na odredjene upite za stabla
//kao sto je maksimalna tezina grane ili cvora na puta od a,b

//radi tako sto stablo izdelimo na grupe cvorova 
//cvorove delimo tako sto ako krenemo od cvora U u njegovu grupu
//ulazi onaj cvor cije je podstablo velicine bar pola velicine stabla U
//i ta dva cvora spaja heavy grana 
//kada vise ne postoji takvo dete cvora onda je to light grana 
//i pokusavamo sada da na dalje rastavljamo stablo
//sada unutar tih grupa se nalaze samo heavy grane
//a grupe su spojene light granama i grupa ima najvise log N

//kada radimo upit prvo proveravamo odgovor u toj grupi u kojoj se nalaze cvorovi a i b
//i onda penjemo onaj koji je dublje navise
//kada se na kraju nalaze u istoj grupi samo proverimo izmedju njih put ali takodje 
//na efikasan nacin

//segmentno ovde sluzi samo kao pomocno sredstvo

struct segtree{int n;vector<ll> seg;vector<ll> a;segtree(){}segtree(int nn,vector<ll> aa){this->n = nn;        seg.resize(4*n+5,-(ll)1e18);        a = aa;    }        ll f(ll x,ll y)    {        return  max(x,y);    }        void build(int id,int tl,int tr)    {        if(tl==tr)        {            seg[id] = a[tl];        }        else        {            int tm = (tl+tr)/2;            build(2*id,tl,tm);            build(2*id+1,tm+1,tr);            seg[id]=f(seg[2*id],seg[2*id+1]);        }    }        ll query(int id,int tl,int tr,int l,int r)    {        if(l > r) return -(ll)1e18;         if(l==tl && r==tr) return seg[id];        int tm = (tl+tr)/2;        return f(query(2*id,tl,tm,l,min(r,tm)),                 query(2*id+1,tm+1,tr,max(l,tm+1),r));    }        void update(int id,int tl,int tr,int p,ll v)    {        if(tl==tr)        {            seg[id]+=v;        }        else        {            int tm = (tl+tr)/2;            if(p<=tm) update(id*2,tl,tm,p,v);            else update(2*id+1,tm+1,tr,p,v);            seg[id] = f(seg[2*id],seg[2*id+1]);        }    }};

struct hld
{
    int n;
    vector<vector<int> >adj;
    vector<ll> a;
    vector<vector<int> > adjw;
    vector<int> parent, d, hv, head, pos;
    int curpos;
    segtree seg;
    
    hld(int n)
    {
        this->n = n;
        adj.resize(n+5); pos.resize(n+5);
        parent.resize(n+5); hv.resize(n+5,-1);
        d.resize(n+5); head.resize(n+5);
        a.resize(n+5,0LL); 
        seg = segtree(n,a);
    }
    
    int dfs(int u)
    {
        int sz = 1;
        int maxsz = 0;
        for(int v : adj[u])
        {
            if(v!=parent[u])
            {
                parent[v] = u;
                d[v] = d[u] + 1;
                int sz2 = dfs(v);
                sz+=sz2;
                if(sz2 > maxsz) 
                {
                    maxsz = sz2;
                    hv[u] = v;
                }
            }
        }
        return sz;
    }
    
    void dodaj(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void decompose(int u,int h)
    {
        head[u] = h;
        pos[u] = ++curpos;
        a[curpos] = 0LL;
        if(hv[u]!=-1) decompose(hv[u],h);
        for(int v : adj[u])
            if(v!=parent[u] && v!=hv[u]) decompose(v,v);
    }
    
    ll query(int a,int b)
    {
        ll res = 0LL;
        for(;head[a]!=head[b];b=parent[head[b]])
        {
            if(d[head[a]] > d[head[b]]) swap(a,b);
            ll curres = seg.query(1,1,n,pos[head[b]],pos[b]);
            res = max(res,curres);
        }
        if(d[a] > d[b]) swap(a,b);
        ll curres = seg.query(1,1,n,pos[a],pos[b]);
        res = max(res,curres);
        return res;
    }
    
    void update(int u,ll val)
    {
        seg.update(1,1,n,pos[u],val);
    }
    
    void init()
    {
        curpos = 0;
        
        seg.build(1,1,n);
        parent[1] = 1;
        dfs(1);
        decompose(1,1);
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