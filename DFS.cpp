#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> adj[200005];
bool vis[200005];
int n;
vector<int> comp;

void dfs(int u)
{
    vis[u] = true;
    comp.push_back(u);
    for(int v : adj[u])
    {
        if(!vis[v]) dfs(v);
    }
}

//moze biti korisno da preracunamo entry time i exit time
//za svaki cvor na primer za stablo ukoliko zelimo da 
//proverimo da li je cvor v predak cvora u dovoljno je da vazi
//tin[u] < tin[v] && tout[u] > tout[v]

int timer = 0;
int col[200005];
int tin[200005];
int tout[200005];

void nadji_komponente()
{
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            comp.clear();
            dfs(i);
            for(int x : comp) cout << x << " ";
            cout << "\n";
        }
    }
}

void dfs2(int u)
{
    tin[u]=timer++;
    col[u] = 1;
    for(int v : adj[u])
    {
        if(col[v]==0) dfs(v);
    }
    col[u] = 2;
    tout[u]=timer++;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    
    
    return 0;
}