#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Dijkstra Algorithm 
//Single source Shortest path
//grane su nenegativne i trazimo najkraci put od s do ostalih cvorova
//O(m log n) gde je m broj grana a n broj cvorova

int d[200005];
int vis[200005];
int pre[200005];
int inf = 1e9;
int n;
vector<pair<int,int>> adj[200005];

vector<int> restorePath(int t,int s)
{
    vector<int> ve;
    while(t!=s)
    {
        ve.push_back(t);
        t=pre[t];
    }
    ve.push_back(t);
    reverse(ve.begin(),ve.end());
    //for(int xx : ve) cout << xx << " ";
    return ve;
}

void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        d[i] = inf;
        vis[i] = false;
    }
    d[s] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({-d[s],s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(pair<int,int> p : adj[u])
        {
            if(d[p.first] > d[u] + abs(p.second))
            {
                d[p.first] = d[u] + abs(p.second);
                pq.push({-d[p.first],p.first}); 
                pre[p.first] = u;//- vrednosti je jer je max heap po defaultu
            }
        }
    }
    vector<int> put = restorePath(n,s);
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    return 0;
}