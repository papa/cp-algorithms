#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct FenwickTree2D
{
   vector<vector<int>> bit;
   int n,m;
   
   FenwickTree2D(int n,int m)
   {
       this->n =  n;
       this->m = m;
       bit.resize(n+1);
       for(int i=1;i<=n;i++) bit[i].resize(m+1);
   }
   
   int sum(int x,int y)
   {
       int ret = 0;
       for(int i=x;i>0;i-=i&-i)
          for(int j=y;j>0;j-=j&-j) ret+=bit[i][j];
       return ret;
   }
   
   void update(int x,int y,int val)
   {
       for(int i=x;i<=n;i+=i&-i)
          for(int j=y;j<=m;j+=j&-j) bit[i][j]+=val;
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