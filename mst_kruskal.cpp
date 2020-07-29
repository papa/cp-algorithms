#include <bits/stdc++.h>

using namespace std;

int p[200005];
int r[200005];
int n,m;

struct grana
{
    int u,v,w;
    bool operator < (grana const& gr)
    {
        return w < gr.w;
    }
};

vector<grana> e;

void make_set(int v)
{
    p[v] = v;
    r[v] = 0;
}

int find_set(int v)
{
    if(p[v]==v) return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a]==r[b]) r[a]++;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    cin >> n >> m;

    for(int i=1;i<=m;i++)
    {
        grana g;
        cin >> g.u >> g.v >> g.w;
        e.push_back(g);
    }

    for(int i=1;i<=n;i++) make_set(i);

    sort(e.begin(),e.end());

    int res=0;
    vector<grana> ans;

    for(int i = 0;i<e.size();i++)
    {
        grana g = e[i];
        if(find_set(g.u)!=find_set(g.v))
        {
           res+=g.w;
           ans.push_back(g);
           union_sets(g.u,g.v);
        }
    }

    return 0;
}
