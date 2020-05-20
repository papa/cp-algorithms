#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Range update and Point Query

struct FenwickTree
{
    vector<int> bit;
    int n;
    int inf = 1e9;
 
    FenwickTreeMin(int n) 
    {
        this->n = n;
        bit.assign(n+1, inf);
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
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
 
    return 0;
}
 