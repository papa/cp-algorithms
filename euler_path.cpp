#include <bits/stdc++.h>

using namespace std;

//Ojlerov put u grafu je put
//koji svaku granu poseti tacno jednom
//Ojlerov ciklus je Ojlerov put tako da
//su mu krajnji i pocetni cvor isti

//Ojlerov ciklus postoji ako je stepen svakog
//cvora paran a ukoliko postoje tacno 2 cvora
//sa neparnim stepenom onda postoji Ojlerov put

//ako postoji samo put vestacki dodajemo grane (v1,v2)
//i onda trazimo ciklus pa u tom ciklusu samo skinemo ove
//dve grane

//ako trazimo ciklus prvo u stek ubacujemo bilo koji cvor
//inace jedan od dva koja imaju neparni stepen

//implementacija moze da se ubrza ako koristimo
//neku unordered strukturu

int n,m;
vector<int> adj[200005];
int deg[200005];
set<pair<int,int> > se;

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
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        deg[i] = adj[i].size();
        cout << deg[i] << endl;
    }

    int fi = -1;
    for(int i=1;i<=n;i++) if(deg[i] > 0) {fi = i;break;}

    if(fi==-1)
    {
        cout << -1;
        return 0;
    }

    int v1 = -1;
    int v2 = -1;
    bool lose = false;
    for(int i=1;i<=n;i++)
    {
        if(deg[i] & 1)
        {
            if(v1==-1) v1 = i;
            else if(v2==-1) v2 = i;
            else lose = true;
        }
    }

    bool bl = true;
    if(v1!=-1)
    {
        for(int i=0;i<adj[v1].size();i++) if(adj[v1][i]==v2) {bl = false;break;}
        if(bl)
        {
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
            deg[v1]++;
            deg[v2]++;
        }
    }

    stack<int> st;
    if(v1==-1) st.push(fi);
    else st.push(v1);
    vector<int> res;
    while(!st.empty())
    {
        //cout << "uso" << endl;
        int u = st.top();
        cout  << "u "<< u << endl;
        if(deg[u] > 0)
        {
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i];
                cout << "v " << v << endl;
                pair<int,int> p1 = make_pair(u,v);
                pair<int,int> p2 = make_pair(v,u);
                //cout << p1.first << " " << p1.second << endl;
                //cout << p2.first << " " << p2.second << endl;
                if(se.find(p1)==se.end() && se.find(p2)==se.end())
                {
                    deg[u]--;
                    deg[v]--;
                    se.insert({u,v});
                    st.push(v);
                    break;
                }
            }
        }
        else
        {
            cout << "gurnuo" << endl;
            res.push_back(u);
            st.pop();
        }
    }

    //for(int i=0;i<res.size();i++) cout << res[i] << " ";
    //cout << endl;

    if(v1!=-1 && bl)
    {
        for(int i = 0;i+1<res.size();i++)
        {
            if((res[i]==v1 && res[i+1]==v2) || (res[i]==v2 && res[i+1]==v1))
            {
                vector<int> res2;
                for(int j=i+1;j<res.size();j++) res2.push_back(res[j]);
                for(int j =1;j<=i;j++) res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++) if(deg[i] > 0) lose = true;

    if(lose)
    {
        cout << -1;
    }
    else
    {
        for(int i=0;i<res.size();i++) cout << res[i] << " ";
    }

    return 0;
}
