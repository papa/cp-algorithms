#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//mostovi u grafu su one grane koje kada se uklone
//povecavaju broj povezanih komponenti za 1(ta komponenta postaje nepovezana)

vector<int> adj[200005];
int tin[200005];
int low[200005];
bool vis[200005];
int n;
int timer;

void los_cvor(int a)
{
    //funkcija koja nesto radi sa cvorovima 
}

void dfs(int u,int p)
{
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int c = 0;
    for(int v : adj[u])
    {
        if(v==p) continue;
        if(vis[v]) low[u] = min(low[u],tin[v]);
        else
        {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] >= tin[u] && p!=-1)
            {
                los_cvor(u);
            }
            c++;
        } 
    }
    
    if(p==-1 && c > 1)
    {
        los_cvor(u);
    }
    
}

void nadji_lose_cvorove()
{
    timer = 0;
    for(int i=1;i<=n;i++) vis[i] =  false;
    for(int i=1;i<=n;i++) tin[i] = low[i] = -1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i,-1);
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