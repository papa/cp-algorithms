#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//neke od primena 
//1) najkraci put u netezinskom grafu
//2) broj povezanih komponenti
//3) najkraci ciklus u usmerenom netezinskom grafu
//4) naci sve cvorove koji se nalaze na nekom najkracem putu izmedju a i b (uslov da[v] + db[v] =da[b])
//5) naci najkraci put parne duzine u grafu. Pravimo novi graf tako da svaki cvor sad ima stanja (c,0) i (c,1)
//gde su 0 i 1 parnosti puta. Sada svaka grana a,b postaje ((a,0),(b,1)) i ((a,1),(b,0)). Trazimo put od (a,0) do (b,0)

vector<int> adj[200005];
int n;
bool vis[200005];
int d[200005];
int p[200005];

void konstruisiPut(int v,int s)
{
    if(vis[v]==false)
    {
        cout << "Nema puta";
        return;
    }
    vector<int> ve;
    while(v!=-1)
    {
            ve.push_back(v);
            v = p[v];
    }
    reverse(ve.begin(),ve.end());
    for(int x : ve) cout << x << " ";
}

void bfs(int s)
{
    vis[s] = true;
    d[s] = 1;
    queue<int> q;
    p[s] = -1;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.push(v);
                d[v] = d[u] + 1;
                p[v] = u;
            }
        }
    }
    
    konstruisiPut(n,s);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    
    
    return 0;
}