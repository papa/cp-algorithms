#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//sve sto je oznaceno sa 1 je za dodavanje vrednosti na segment
//sve sto je oznaceno sa 2 je postavljanje vrednsoti za segment

struct segment_tree_lazy
{
    vector<ll> seg;
    vector<ll> a;
    vector<ll> lazy;
    vector<bool> mark;
    int n;
    ll inf = (ll)1e18;
    
    segment_tree_lazy()
    {
        
    }
    
    segment_tree_lazy(int nn)
    {
        this->n = nn;
        seg.resize(4*nn+5,0LL);
        lazy.resize(4*nn+5,0LL);
        mark.resize(4*nn+5,false);
    }
    
    segment_tree_lazy(int nn,vector<ll> aa)
    {
        this->n = nn;
        seg.resize(4*nn+5);
        a = aa;
    }
    
    void build(int id,int tl,int tr)
    {
        if(tl==tr)
        {
            seg[id] = a[tl];
        }
        else
        {
            int tm = (tl+tr)/2;
            build(2*id,tl,tm);
            build(2*id+1,tm+1,tr);
            seg[id] = 0;
        }
    }
    
    void push1(int id)
    {
        seg[2*id]+=lazy[id];
        lazy[2*id]+=lazy[id];
        seg[2*id+1]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
        lazy[id] = 0;
    }
    
    void push2(int id)
    {
        if(mark[id])
        {
            seg[2*id] = seg[2*id+1] = seg[id];
            mark[2*id] = mark[2*id+1] = true;
            mark[id] = false;
        }
    }
    
    void update2(int id,int tl,int tr,int l,int r,int v)
    {
        if(l > r) return;
        if(l==tl && r==tr)
        {
            seg[id] = v;
            mark[id] = true;
        }
        else
        {
            push2(id);
            int tm = (tl+tr)/2;
            update2(2*id,tl,tm,l,min(r,tm),v);
            update2(2*id+1,tm+1,tr,max(l,tm+1),r,v);
        }
    }
    
    void update1(int id,int tl,int tr,int l,int r,ll v)
    {
        if(l > r) return;
        if(l==tl && tr==r)
        {
            seg[id]+=v;
            lazy[id]+=v;
        }
        else
        {
            push1(id);
            int tm = (tl+tr)/2;
            update1(2*id,tl,tm,l,min(r,tm),v);
            update1(2*id+1,tm+1,tr,max(l,tm+1),r,v);
            seg[id]=min(seg[2*id],seg[2*id+1]);
        }
    }
    
    int query2(int id,int tl,int tr,int p)
    {
        if(tl==tr) return seg[id];
        push2(id);
        int tm = (tl+tr)/2;
        if(p<=tm) return query2(2*id,tl,tm,p);
        else return query2(2*id+1,tm+1,tr,p);
    }
    
    ll query1(int id,int tl,int tr,int l,int r)
    {
        if(l > r) return inf;
        if(l<=tl && tr<=r) return seg[id];
        push1(id);
        int tm = (tl+tr)/2;
        return min(query1(2*id,tl,tm,l,min(r,tm)),
                    query1(2*id+1,tm+1,tr,max(l,tm+1),r));//ili neka druga funkcija
    }
    
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    int n,q;
    cin >> n >> q;
    segment_tree_lazy seg = segment_tree_lazy(n);
    for(int i=1;i<=n;i++) 
    {
        ll x;
        cin >> x;
        seg.update1(1,1,n,i,i,x);
    }
    
    while(q--)
    {
        char ch;
        cin >> ch;
        if(ch=='u')
        {
            int x,y;
            ll z;
            cin >> x >> y >> z;
            seg.update1(1,1,n,x,y,z);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << seg.query1(1,1,n,l,r) << "\n";
        }
    }
    
    return 0;
}