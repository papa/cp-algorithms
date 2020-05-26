#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//bipartitni graf definisemo kao graf 
//u kojem je moguce podeliti cvorve u 2 grupe
//tako da svaka grana povezuje 2 cvora iz razlicite grupe
//tacnije da su svaka 2 susedna cvora drugacije boje

int col[200005];
vector<int> adj[200005];
int n;

bool check_biparite()
{
    //bfs za svaku komponentu pokrenemo
    bool bip = true;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0)
        {
            q.push(i);
            col[i] = 1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int v : adj[u])
                {
                    if(col[v]==0)
                    {
                        if(col[u]==1) col[v] = 2;
                        else col[v] = 1;
                        q.push(v);
                    }
                    else
                    {
                        bip&=col[u]!=col[v];
                    }
                }
            }
        }
    }
    return bip;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    return 0;
}