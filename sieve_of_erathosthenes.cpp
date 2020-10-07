#include <bits/stdc++.h>

using namspace std;

void sieve(int n)
{
  vector<int> prime(n+1,1);
  prime[0] = prime[1] = 0;
  for(int i =2;i*i<=n;i++)
  {
     if(prime[i])
     {
        for(int j=i*i;j<=n;j+=i) prime[j] = 0;
     }
  }
}

int segmented_sieve(int n)
{
  const int s = 10000;

  vector<int> primes;
  int nsqrt  = sqrt(n);
  vector<char> isp(nsqrt+1,true);
  for(int i =2;i<=nsqrt;i++)
  {
    if(isp[i])
    {
      primes.push_back(i);
      for(int j =i*i;j<=nsqrt;j+=i) isp[j] = false;
    }
  }

  int res = 0;
  vector<char> block(s);
  for(int k = 0;k*s<=n;k++)
  {
    fill(block.begin(),block.end(),true);
    int start = k*s;
    for(int p : primes)
    {
      int sidx = (start+p-1)/p;
      int j = max(sidx,p)*p-start;
      for(;j<s;j+=p) block[j] = false;
    }
    if(k==0) block[0] = block[1] = false;
    for(int i =0;i<s && start+i<=n;i++)
        if(block[i]) res++;
  }
  return res;
}

vector<bool> segmented_sieve_range(ll l,ll r)
{
  ll lim = sqrt(r);
  vector<bool> mark(lim+1,false);
  vector<ll> primes;
  for(ll i =2;i<=lim;i++)
  {
    if(!mark[i])
    {
      primes.emplace_back(i);
    }
  }
}

int int main()
{

  return 0;
}
