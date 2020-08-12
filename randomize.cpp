#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

size_t dajnekiseed()
{
    thread t([](){});
    int rez = reinterpret_cast<size_t>(t.native_handle());
    t.join();
    return rez;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    mt19937 eng
    (
        chrono::high_resolution_clock::now().time_since_epoch().count()
        ^
        dajnekiseed()
    );

    uniform_int_distribution uid(0LL,321321321321321321LL);
    
    int a[5] = {0,1,2,3,4};
    
    shuffle(a,a+5,eng);
    
    for(int i=0;i<5;i++) cout << a[i] << " ";
    
    cout << uid(eng);
    
    return 0;
}
