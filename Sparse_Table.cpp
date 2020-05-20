#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//odlicna struktura kada se niz 
//nad kojim se vrse upit ne modifikuje
//veliki broj stvar radi u O(log N) ali 
//RMQ moze u O(1). Radi za sve operacije 
//koje su idempotente (ako je operacija *)
//tada je a*a = a
//razmatramo zbir ovde

struct SparseTable
{
   int n,k;
   vector<vector<int> > sparse;
   vector<int> lg;
   
   SparseTable()
   {
       
   }
   
   SparseTable(int n,int k)
   {
       this->n = n;
       this->k = k;
       sparse.resize(n+3);
       lg.resize(n+1);
       for(int i=0;i<=n+2;i++) sparse[i].resize(k+2);
   }
   
   void precompute()
   {
       lg[1] = 0;
       for(int i=2;i<=n;i++) lg[i] = lg[i/2] + 1;
   }
   
   void build(int a[])
   {
        for(int i=1;i<=n;i++) sparse[i][0] = a[i];
    
        for(int j = 1;j<=k;j++)
            for(int i=1;i + (1 << j) <=n+1;i++)  sparse[i][j] = sparse[i][j-1] + sparse[i + (1 << (j-1))][j-1];
   }
   
   int sum(int l,int r)
   {
         int s=0;
        for(int i=k;i>=0;i--)
        {
            if((1 << i) <=r-l+1)
            {
                s+=sparse[l][i];
                l+=(1 << i);
            }
        }
    }
    
    int getmin(int l,int r)
    {
        int j = lg[r-l+1];
        return min(sparse[l][j],sparse[r-(1 << j)+1][j]);
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
 