#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//queue,stack with minimum operation 
stack<pair<int,int>> st;

void dodaj(int x)
{
    int nm = st.empty() ? x : min(x,st.top().second);
    st.push({x,nm});
}

void skini()
{
    int sklonjen = st.top().first;
    st.pop();
}

int getmin()
{
    return st.top().second;
}

//queue with min operation se zapravo 
//implementira preko dva steka

stack<pair<int,int>> s1,s2;

int getmin2()
{
    if(s1.empty() || s2.empty()) return s1.empty() ? s2.top().second : s1.top().second;
    else return min(s1.top().second,s2.top().second);
}

void dodaj2(int x)
{
    int m = s1.empty() ? x : min(x,s1.top().second);
    s1.push({x,m});
}

void skini2()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            int x = s1.top().second;
            s1.pop();
            int m = s2.empty() ? x : min(x,s2.top().second);
            s2.push({x,m});
        }
    }
    int skinut = s2.top().first;
    s2.pop();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    
   
    return 0;
}
 