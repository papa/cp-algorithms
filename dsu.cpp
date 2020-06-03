#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//disjoint set union
//primene:
//1) MST - Kruskal
//2) Broj komponenti u grafu
//3) Cuvanje odredjenih informacija o nekom setu 
//4) Painting subarrays offline

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
        return p[v] = find_set(p[v]);
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

struct DSU_with_distance 
{
    //ova struktura takodje cuva i udaljenost
    //svakog cvora od svog predstavnika
    int n;
    vector<pair<int,int>> p;
    vector<int> rank;
    
    DSU_with_distance()
    {
        
    }
    
    void build()
    {
        for(int i=1;i<=n+1;i++) 
        {
            p[i] = {i,0};
            rank[i] = 0;
        }
    }
    
    DSU_with_distance(int nn)
    {
        this->n = nn;
        p.resize(nn+2);
        rank.resize(nn+2);
        build();
    }
    
    pair<int,int> find_set(int v)
    {
        if(v!=p[v].first)
        {
            int len = p[v].second;
            p[v] = find_set(p[v].first);
            p[v].second+=len;
        }
        return p[v];
    }
    
    void union_sets(int a,int b)
    {
        a = find_set(a).first;
        b = find_set(b).second;
        if(a!=b)
        {
            if(rank[a] < rank[b]) swap(a,b);
            p[b] = {a,1};
            if(rank[a]==rank[b]) rank[a]++;
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
