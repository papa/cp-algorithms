#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Range update and Range query
//koristimo isti Fenwick pri cemu 
//koristimo dva i update radimo drugacije

struct FenwickTree
{
    vector<int> bit;
    int n;
    
    FenwickTree()
    {
        
    }
    
    FenwickTree(int n) 
    {
        this->n = n;
        bit.assign(n+1, 0);
    }
 
    void updateRange(int l,int r,int x)
    {
        update(l,x);
        update(r+1,-x);
    }
 
    int point_query(int r)
    {
        return sum(r);
    }
 
    int sum(int r) 
    {
        int ret = 0;
        for(int i =r;i;i-=i&-i) ret+=bit[i];
        return ret;
    }
 
    void update(int p, int val) 
    {
        for(int i=p;i<=n;i+=i&-i) bit[i]+=val; 
    }
};
 
FenwickTree b1,b2; 
 
void addRange(int l,int r,int x)
{
    b1.update(l,x);
    b1.update(r+1,-x);
    b2.update(l,x*(l-1));
    b2.update(r+1,-x*r);
}
 
int prefix_sum(int p)
{
    return b1.sum(p)*p - b2.sum(p);
}
 
int rangeSum(int l,int r)
{
    return prefix_sum(r) - prefix_sum(l-1);
}
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
 
 
    return 0;
}
 