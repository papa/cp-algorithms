#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//modulo operation
//kada je potrebno da se nesto ispise % neki broj(uglavnom prost)

struct ModuloOperation
{
    ll mod;
    
    ModuloOperation()
    {
        
    }
    
    ModuloOperation(ll m)
    {
        this->mod = m;
    }
    
    ll fix(ll a)
    {
        a%=mod;
        if(a < 0LL) a+=mod;
        return a;
    }
    
    ll saberi(ll a,ll b)
    {
        a = fix(a);
        b = fix(b);
        return fix(a+b);
    }
    
    ll mnozi(ll a,ll b)
    {
        a=fix(a);
        b=fix(b);
        return fix(a*b);
    }
    
    ll oduzmi(ll a,ll b)
    {
        a=fix(a);
        b=fix(b);
        return fix(a-b);
    }
    
    //standardno binarno stepenovanje
    ll binpow(ll a,ll b)
    {
        ll r = 1LL;
        while(b > 0)
        {
            if(b%2==1LL) r=mnozi(a,r);
            a = mnozi(a,a);
            b=b/2LL;
        }
        
        return r;
        
        //rekurzivno
        if(b==0LL) return 1LL;
        if(b==1LL) return a;
        ll x = binpow(a,b/2LL);
        if(b%2==1LL) return mnozi(mnozi(x,x),a);
        return mnozi(x,x);
    }
    
    //ovo radi za proste brojeve
    ll deli(ll a,ll b)
    {
        return mnozi(a,binpow(b,mod-2));
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