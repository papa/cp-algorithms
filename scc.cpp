#include <bits/stdc++.h>

using namespace std;

//jako povezana komponenta u usmerenom grafu je 
//skup cvorova takav da je moguce doci iz svakog cvora 
//tog skupa do nekog drugog cvora tog skupa. Jako povezane komponente
//su disjunkte za odredjeni graf i ako svaku od njih predstavimo kao 
//jedan cvor dobijamo condensation grapf koji nema ciklus.

//svaka grana izmedju dve jako povezane komponente je usmerena tako da
// tout[c] > tout[c'] gde su vremena izlaska iz tih komponenti

//imamo grafove G i G(t) gde je G(t) transponovani graf sto znaci
//da je smer svake grane okrenut u transponovanom grafu

//dfs1 sortira cvorove po izlaznom vremenu
//a zatim u G(t) se traze jako povezane komponente
//tako sto svi cvorovi koji se posete u jednom
//obilasku pripadaju istoj komponenti

int n,m;
vector<int> adj[200005];
vector<int> adjt[200005]; // za transponovan graf
bool vis[200005];
vector<int> ord;
vector<int> comp;

void dfs1(int u)
{
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u)
{
    vis[u] = true;
    comp.push_back(u);
    for(int v : adjt[u]) 
        if(!vis[v]) dfs2(v);
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
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++) vis[i] = false;
   
    for(int i=1;i<=n;i++) 
        if(!vis[i]) dfs1(i);
    
    for(int i=1;i<=n;i++) vis[i] = false;
    
    for(int i=0;i<n;i++)
    {
        int u = ord[n-i-1];
        if(!vis[u])
        {
            dfs2(u);
            for(int x : comp) cout << x << " "; //stampa se komponenta
            cout << "\n";
            comp.clear();
        }
    }
    
    return 0;
}