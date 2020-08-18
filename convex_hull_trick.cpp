#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll isq = - (1LL << 62);
 
struct line
{
    ll m,b;
    
    mutable function<const line *()> succ;
    
    bool operator < (const line &l) const
    {
        if(l.b!=(isq)) return m < l.m;
        const line *s = succ();
        if(!s) return 0;
        ll x = l.m;
        return b - s->b < (s->m - m)*x;
    }
};
 
struct hulldynamic : public multiset<line> 
{
    bool bad(iterator y)
    {
        iterator z = next(y);
        if(y==begin())
        {
            if(z==end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        iterator x = prev(y);
        if(z==end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double)(z->m - y->m) >= (y->b - z->b) *(long double)(y->m - x->m);
    }
    
    void insert_line(ll m,ll b)
    {
        iterator y = insert({m,b});
        y->succ = [=] {return next(y) == end() ? 0 : &*next(y);};
        if(bad(y))
        {
            erase(y);
            return;
        }
        while(next(y) != end() && bad(next(y))) erase(next(y));
        while(y!=begin() && bad(prev(y))) erase(prev(y));
    }
    
    ll get(ll x)
    {
        line li = *lower_bound((line){x,isq});
        return li.m*x + li.b;
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