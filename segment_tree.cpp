#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//svaki cvor je odgovoran za odredjeni segment
//slozenost operacije je O(log N)
//neke od operacija koje se mogu raditi na segmentnom su
//1) zbir
//2) proizvod 
//3) max i min
//4) gcd/lcm
//5) k-ta nula u nizu
//6) prvi broj u podnizu koji je veci od x
//7) prefiksna suma koja je jednaka s

struct segment_tree
{
    int n;
    vector<ll> seg;
    vector<ll> a;
    
    segment_tree()
    {
        
    }
    
    segment_tree(int nn,vector<ll> aa)
    {
        this->n = nn;
        seg.resize(4*n+5,0LL);
        a = aa;
    }
    
    ll f(ll x,ll y)
    {
        //moze da bude max,min,zbir...
        return x+y;
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
            seg[id]=f(seg[2*id],seg[2*id+1]);
        }
    }
    
    ll query(int id,int tl,int tr,int l,int r)
    {
        if(l > r) return 0; //ovde se vraca vrednost u zavisnosti od f-je u stablu
        if(l==tl && r==tr) return seg[id];
        int tm = (tl+tr)/2;
        return f(query(2*id,tl,tm,l,min(r,tm)),
                 query(2*id+1,tm+1,tr,max(l,tm+1),r));
    }
    
    void update(int id,int tl,int tr,int p,ll v)
    {
        if(tl==tr)
        {
            seg[id] = v;
        }
        else
        {
            int tm = (tl+tr)/2;
            if(p<=tm) update(id*2,tl,tm,p,v);
            else update(2*id+1,tm+1,tr,p,v);
            seg[id] = f(seg[2*id],seg[2*id+1]);
        }
    }
};



//za odredjeni segment [l1,r1] naci segment [l2,r2] l<=l2,r2<=r tako da je suma maksimalna
struct segment_tree_2
{
    struct data
    {
        int sum;
        int pref;
        int suf;
        int ans;
    };

    //cuvamo za svaki segment njegovu sumu 
    //maksimalni prefiks,maksimalni sufiks
    //kao i resenje tog segmenta
    
    int n;
    vector<data> seg;
    vector<int> a;
    
    segment_tree_2()
    {
        
    }
    
    segment_tree_2(int nn)
    {
        this->n = nn;
        seg.resize(4*n+5);
    }
    
    segment_tree_2(int nn,vector<int> aa)
    {
        this->n = nn;
        seg.resize(4*n+5);
        a = aa;
    }
    
    data f(data l,data r) //kombinovanje dva segmenta
    {
        data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref,l.sum + r.pref);
        res.suf = max(r.suf,r.sum+l.suf);
        res.ans = max(max(l.ans,r.ans),r.pref + l.suf);
        return res;
    }
    
    data novi(int x)
    {
        data res;
        res.sum = x;
        res.pref = res.suf = res.ans = max(0,x);
        return res;
    }
    
    void build(int id,int tl,int tr)
    {
        if(tl==tr)
        {
            seg[id] = novi(a[tl]);
        }
        else
        {
            int tm = (tl+tr)/2;
            build(2*id,tl,tm);
            build(2*id+1,tm+1,tr);
            seg[id]=f(seg[2*id],seg[2*id+1]);
        }
    }
    
    data query(int id,int tl,int tr,int l,int r)
    {
        if(l > r) return novi(0); 
        if(l==tl && r==tr) return seg[id];
        int tm = (tl+tr)/2;
        return f(query(2*id,tl,tm,l,min(r,tm)),
                 query(2*id+1,tm+1,tr,max(l,tm+1),r));
    }
    
    void update(int id,int tl,int tr,int p,int v)
    {
        if(tl==tr)
        {
            seg[id] = novi(v);
        }
        else
        {
            int tm = (tl+tr)/2;
            if(p<=tm) update(id*2,tl,tm,p,v);
            else update(2*id+1,tm+1,tr,p,v);
            seg[id] = f(seg[2*id],seg[2*id+1]);
        }
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
