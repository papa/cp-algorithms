#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct FenwickTree
{
   vector<int> bit;
   int n;
   
   FenwickTree(int n)
   {
       this->n =  n;
       bit.assign(n+1,0);
   }
   
   FenwickTree(vector<int> a) : FenwickTree(a.size())
   {
       for(int i=0;i<(int)a.size();i++) update(i,a[i]);
   }
   
   int sum(int r)
   {
       int ret = 0;
       for(int i =r;i > 0;i-=i&-i) ret+=bit[i];
       return ret;
   }
   
   int sum(int l,int r)
   {
       return sum(r) - sum(l-1);
   }
   
   void update(int p,int val)
   {
       for(int i = p;i <= n;i+=i&-i) bit[i]+=val;
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