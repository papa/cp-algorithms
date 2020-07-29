#include <bits/stdc++.h>

using namespace std;

int n,m;
int inf = 1e9;

struct grana
{
    int w=inf;
    int to = -1;
    
    bool operator < (grana const& gr)
    {
        return make_pair(w,to) < make_pair(gr.w,gr.to);
    }
};

vector<grana> adj[200005];

void prim()
{
    int ans = 0;
    vector<grana> min_e(n+5);
    min_e[1].w = 0;
    set<pair<int,int> > q;
    q.insert({1,0});
    vector<bool> sel(n+5,false);
    for(int i=1;i<=n;i++)
    {
        if(q.empty())
        {
            cout << "Nema mst" << endl;
            exit(0);
        }

        int v = q.begin()->second;
        sel[v] = true;
        ans+=q.begin()->first;
        q.erase(q.begin());

        if(min_e[v].to!=-1) cout << v << " " << min_e[v].to << endl;

        for(int i = 0;i<adj[v].size();i++)
        {
            grana g = adj[v][i];
            if(!sel[g.to] && g.w < min_e[g.to].w)
            {
                q.erase({min_e[g.to].w,g.to});
                min_e[g.to] = {g.w,v};
                q.insert({g.w,g.to});
            }
        }
    }

    cout << ans << endl;
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
        int u;
        cin >> u >> g.to >> g.w;
        adj[u].push_back(g);
    }

    prim();


    return 0;
}
