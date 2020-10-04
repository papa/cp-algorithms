#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binpow(ll a,ll b)
{
  if(b<=0) return 1LL;
  ll res = binpow(a,b/2);
  if(b%2) return res*res*a;
  else return res*res;
}

ll binpow2(ll a,ll b)
{
  ll res = 1LL;
  while(b > 0)
  {
    if(b%2) res = res*a;
    a = a*a;
    b>>=1;
  }
  return res;
}

pair<ll,ll> fib(int n)
{
  if(n==0) return make_pair(0LL,1LL);

  pair<ll,ll> p = fib(n >> 1);
  ll c = p.first*(2LL*p.second - p.first);
  ll d = p.first*p.first + p.second*p.second;
  if(n&1) return make_pair(d,c+d);
  else return make_pair(c,d);
}

vector<int> f(vector<int> a,vector<int> p)
{
  vector<int> v(a.size());
  for(int i =1;i<v.size();i++) v[i]=a[p[i]];
  return v;
}

vector<int> binpow_perm(vector<int> a,vector<int> p,int k)
{
  while(k > 0)
  {
    if(k&1) a = f(a,p);
    k>>=1;
    if(k > 0) p = f(p,p);
  }
  return a;
}

ll mult_mod(ll a,ll b,ll mod)
{
  if(a==0) return 0LL;
  if(a&1) return (2LL*mult_mod((a-1)/2LL,b,mod)%mod+b)%mod;
  return 2LL*mult_mod(a/2LL,b,mod)%mod;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  return 0;
}
