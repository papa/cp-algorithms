#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//disjoint set union

struct DSU //sa svim optimizacijama u proseku je slozenost konstanta
{
    int n;
    vector<int> p;
    vector<int> sz;
    
    DSU()
    {
        
    }
    
    void build()
    {
        for(int i=1;i<=n;i++) 
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    
    DSU(int nn)
    {
        this->n = nn;
        p.resize(nn+1);
        sz.resize(nn+1);
        build();
    }
    
    int find_set(int v)
    {
        if(v==p[v]) return v;
        return p[v] = find_set(v);
    }
    
    //ovde je uradjen union by size
    //moze takodje i union by rank ali je ista 
    //slozenost
    void union_sets(int a,int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a!=b)
        {
            if(sz[a] < sz[b]) swap(a,b);
            p[b] = a;
            sz[a]+=sz[b];
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