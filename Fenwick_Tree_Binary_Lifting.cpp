#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//problem je da nadjemo lower_bound neke monotone
//funkcije u bit-u. Ovo mozemo da uradimo binarna + bit 
//sto je daje slozenost O(N log^2 N) a mozemo i tehnikom
//koja lici na binary lifting i vrsi se nad pozicijama
//implementirana je dole. Slozenost je O(N log N)
//https://codeforces.com/blog/entry/61364

struct FenwickTree
{
   vector<int> bit;
   int n;
   
   FenwickTree()
   {
       
   }
   
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
   
   int get(int p)
   {
       return bit[p];
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

FenwickTree f;
int n;
int logn;


int bit_search(int v)
{
    int s = 0;
    int p = 0;
    for(int i=logn;i>=0;i--)
    {
        if(p + (1 << i) < n && s + f.get(p+(1<<i)) < v)
        {
            s+=f.get(p + (1<<i));
            p+=(1 << i);
        }
    }
    
    return p+1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
 
   
    return 0;
}
 