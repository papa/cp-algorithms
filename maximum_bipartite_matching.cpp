#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int mat[1005][1005];
bool vis[1005];
int a[1005];

bool bip(int u)
{
    for(int i = 1;i<=n;i++)
    {
        if(mat[u][i] && !vis[i])
        {
            vis[i] = true;

            if(a[i]==-1 || bip(a[i]))
            {
                a[i] = u;
                return true;
            }
        }
    }

    return false;
}

int maxMatch()
{
    for(int i=1;i<=n;i++) a[i] = -1;
    int res = 0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) vis[j] = false;
        if(bip(i)) res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    cin >> m >> n;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin >> mat[i][j];

    cout << maxMatch();

    return 0;
}
