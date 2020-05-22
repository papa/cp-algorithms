#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//single source shortest path problem samo 
//kada su tezine grana 0 i 1

//nadogradjnja ovog je Dial Algorithm
//koji radi kada su tezine grana <=k 


vector<pair<int,int>> adj[200005];
int d[200005];
int n;
int inf = 1e9;

void bfs01(int s)
{
    for(int i=1;i<=n;i++) d[i] = inf;
    deque<int> q;
    d[s] = 0;
    q.push_front(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for(pair<int,int> p : adj[u])
        {
            int v=  p.first;
            int w = p.second;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                if(w==1) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    
    
    return 0;
}