#include <bits/stdc++.h>

using namespace std;

//bellman ford algoritam
//single souce shortest path algoritam
//pri cemu moze da nadje najkraci put i kada
//imamo grane negativnih vrednosti
//kao i da detektuje negativni ciklus

struct grana
{
    int u,v,w;
};

int n;
int m;
int inf = 1e9;
vector<grana> e;

void solve1(int s,int t) //za put od s do t
{
    vector<int> d(n+5,inf);
    vector<int> p(n+5,-1);
    d[s] = 0;
    for(;;)
    {
        bool b = false;
        for(int j=0;j<m;j++)
        {
            if(d[e[j].u] < inf)
            {
                if(d[e[j].v] > d[e[j].u] + e[j].w)
                {
                    d[e[j].v] = d[e[j].u] + e[j].w;
                    p[e[j].v] = e[j].u;
                    b = true;
                }
            }
        }

        if(!b) break;
    }

    if(d[t]==inf)
    {
        cout << "nema puta" << endl;
    }
    else
    {
        vector<int> path;
        for(int cur = t;cur!=-1;cur=p[cur]) path.push_back(cur);
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++) cout << path[i] << " ";
    }
}

void solve2(int s) // za trazenje negativnog ciklusa
{
    vector<int> d(n+5,inf);
    d[s] = 0;
    vector<int> p(n+5,-1);
    int x;
    for(int i=0;i<n;i++)
    {
        x = -1;
        for(int j =0;j<m;j++)
        {
            if(d[e[j].u] < inf)
            {
                if(d[e[j].v] > d[e[j].u] + e[j].w)
                {
                    d[e[j].v] = max(-inf,d[e[j].u] + e[j].w);
                    p[e[j].v] = e[j].u;
                    x= e[j].v;
                }
            }
        }
    }

    if(x==-1)
    {
        cout << "nema negativnog ciklusa\n";
    }
    else
    {
       int y = x;
       for(int i=0;i<n;i++) y = p[y];

       vector<int> cyc;
       for(int cur = y;;cur=p[cur])
       {
           cyc.push_back(cur);
           if(cur==y && cyc.size() > 1) break;
       }

       reverse(cyc.begin(),cyc.end());

       for(int i=0;i<cyc.size();i++) cout << cyc[i] << " ";
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
