#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//u svakom cvoru se cuvaju svi elementi 
//segmenta koji taj cvor pokriva O(n log n) memorije
//jedan od problema je na segmentu [l,r] naci
//najmanji element koji je veci ili jednak x

struct merge_sort_tree
{
    vector<vector<int> > seg;
    vector<multiset<int>> seg2;
    vector<int> a;
    int n;
    int inf = 1e9;
    
    merge_sort_tree()
    {
        
    }
    
    merge_sort_tree(int nn)
    {
        this->n = nn;
        seg.resize(4*nn+5);
    }
    
    merge_sort_tree(int nn,vector<int> aa)
    {
        this->n = nn;
        seg.resize(4*nn+5);
        a = aa;
    }
    
    void build(int id,int tl,int tr)
    {
        if(tl==tr)
        {
            seg[id] = vector<int>(1,a[tl]);
        }
        else
        {
            int tm = (tl+tr)/2;
            build(2*id,tl,tm);
            build(2*id+1,tm+1,tr);
            merge(seg[2*id].begin(),seg[2*id].end(),seg[2*id+1].begin(),seg[2*id+1].end(),back_inserter(seg[id]));
        }
    }
    
    int query(int id,int tl,int tr,int l,int r,int x)
    {
        if(l > r) return inf;
        if(l==tl && r==tr)
        {
            vector<int>::iterator it = lower_bound(seg[id].begin(),seg[id].end(),x);
            if(it!=seg[id].end()) return *it;
            return inf;
        }
        int tm = (tl+tr)/2;
        return min(query(2*id,tl,tm,l,min(r,tm),x),
                   query(2*id+1,tm+1,tr,max(l,tm+1),r,x));
    }
    
    //za update je potreba mulitset i onda je update O(log^2 N)
    //ovde je update implementiran samo sa multisetom ali 
    //se build i query lako modifikuju
    void update(int id,int tl,int tr,int p,int v)
    {
        seg2[id].erase(seg2[id].find(a[p]));
        seg2[id].insert(v);
        if(tl!=tr)
        {
            int tm = (tl+tr)/2;
            if(p<=tm) update(2*id,tl,tm,p,v);
            else update(2*id+1,tm+1,tr,p,v);
        }
        else
        {
            a[p] = v;
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