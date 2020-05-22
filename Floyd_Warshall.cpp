#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//na pocetku je d[i][j] = w[i][j] gde je w tezina grane 
//izmedju i,j a ako ne postoji onda stavimo na neku veliku
//vrednost. Na pocetku je p[i][j] = i
//cesto se koristi i kada imamo neku funkciji a[i][j] pa zelimo
//da preracunamo zapravo najmanje takvo a[i][j] ako je po uslovu da 
//a[i][j] iz matrice nije uvek najmanje

int d[305][305];
int p[305][305];
int inf = 1e9;
int n;

void nadjiPut(int a,int b)
{
    int pp = p[a][b];
    int c = b;
    vector<int> ve;
    while(c!=a)
    {
        ve.push_back(c);
        c = pp;
        pp = p[a][c];
    }
    ve.push_back(a);
    reverse(ve.begin(),ve.end());
    for(int x : ve) cout << x << " ";
}

void floyd_warshall()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) 
            {
                if(d[i][k] < inf && d[k][j] < inf) //ovako je dobro da se kuca kada postoje negativne grane
                {
                    //d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                    if(d[i][k] + d[k][j] < d[i][j])
                    {
                        p[i][j] = k;
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
    }
    
    nadjiPut(1,n);
}




int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    
    
    
    
    return 0;
}