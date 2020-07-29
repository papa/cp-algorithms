#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;
int n;
vector<int> adj[200005];

struct grana
{
    int w = inf;
    int to = -1;
};

void prim()
{
    int ans = 0;
    vector<bool> sel(n+5,false);
    vector<pair<int,int> > min_e(n+5);
    min_e[1].first = 0;

    for(int i=1;i<=n;i++)
    {
        int v = -1;
        for(int j=1;j<=n;j++)
            if(!sel[j] && (v==-1 || min_e[j].first < min_e[v].first)) v = j;

        if(min_e[v].first==inf)
        {
            cout << "Nema mst" << endl;
            exit(0);
        }

        sel[v] = true;
        ans+=min_e[v].first;
        if(min_e[v].second!=-1) cout << v << ' ' << min_e[v].second << endl;

        for(int to = 0;to<n;to++)
        {
            if(adj[v][to] < min_e[to+1].first)
            {
                min_e[to+1] = {adj[v][to],v};
            }
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);




    return 0;
}
