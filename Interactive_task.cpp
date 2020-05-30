#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//interactive tasks
//kod interaktivnih zadataka nas program
//zadaje upite prema interaktoru i on nam vraca 
//odgovarajuce vrednosti. Na osnovu tih vrednosti mi 
//izvrsavamo svoj program na odredjeni nacin i kada smo sigurni 
//da znamo resenje uglavnom ispisujemo ! resenje
//bitno je da odradimo flush operaciju za svaki output jer
//ako ne uradimo taj output se zadrzava u buffer memoriji 
//i ne ispisuje se lepo sto kvari interakciju 
//ispod je uradjen zadatak https://codeforces.com/gym/101021/problem/1

string query(int x)
{
    cout << x << endl;
    //cout << flush << endl;
    string s;
    cin >> s;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int lo = 1;
    int hi = 1e6;

    for(int i=1;i<=25;i++)
    {
        int mid = (lo+hi+1)/2;
        string s = query(mid);

        if(s=="<") hi=mid-1;
        else lo = mid;
    }

    cout << "! " << lo << endl;

    return 0;
}
