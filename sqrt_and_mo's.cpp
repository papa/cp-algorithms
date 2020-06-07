#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//sqrt decomposition i Mo's algorithm
//niz se podeli u bucket-e duzine sqrt(n) i 
//za svaki se preracuna suma 
//i zatim kad naidje upit suma(l,r) od l pa do pocetka 
//nekog bucket-a se racuna rucno a zatim preracunate sume za bucket
//takodje rucno mora i kraj da se izracuna

const int szc = 500; //najbolje da se ovako definise velicina bloka
int sz;  
int n;
int a[200005];
int b[200005];
int q;

int blok(int p)
{
    return (p+sz-1)/sz;
}

void preprocess()
{
    sz = (int)sqrt(n+.0)+1;
    for(int i=1;i<=n;i++) b[blok(i)]+=a[i];
}

int resiupit(int l,int r)
{
    int s = 0;
    for(int i=l;i<=r;)
    {
        if(i%sz==1 && i+sz-1<=r)
        {
            s+=b[blok(i)];
            i+=sz;
        }
        else
        {
            s+=a[i];
            i++;
        }
    }
    
    //drugi nacin da se resi upit(brzi)
    s = 0;
    int bl = blok(l);
    int br = blok(r);
    if(bl==br)
    {
        for(int i=l;i<=r;i++) s+=a[i];
    }
    else
    {
        for(int i = l,e=bl*sz;i<=e;i++) s+=a[i];
        for(int i=bl+1;i<=br-1;i++) s+=b[i];
        for(int i=(br-1)*sz+1;i<=r;i++) s+=a[i];
    }
    
    return s;
}

void update(int p,int v)
{
    b[blok(p)]-=a[p];
    b[blok(p)]+=v;
    a[p]=v;
}

void dodaj(int p)
{
    
}

void skloni(int p)
{
    
}

int get_ans()
{
    return 0;
}

struct query
{
    int l,r,idx;
    bool operator < (query q) const
    {
        return make_pair(blok(l),r) < make_pair(blok(q.l),q.r);
    }
};

vector<int> mo_s_algo(vector<query> qs)
{
    vector<int> ans(qs.size());
    sort(qs.begin(),qs.end());
    
    //ovo je offline algoritam 
    //koji sortira upite po bloku u kojem se nalazi leva granica 
    //a zatim po desnoj 
    //i onda se pomeraju indeksi od jednog do drugog upita 
    //slozenost algoritma je O((n+q)sqrt(n))
    //funkcije dodaj,skloni i get_ans nisu implementirane
    //ali njihova funkcija je da sa odredjenim elementima niza odradi nesto
    //na primer doda ih na sumu ili oduzme
    
    int curl = 1;
    int curr=0;
    for(query q : qs)
    {
        while(curl > q.l)
        {
            curl--;
            dodaj(curl);
        }
        while(curr < q.r)
        {
            curr++;
            dodaj(curr);
        }
        while(curl < q.l)
        {
            skloni(curl);
            curl++;
        }
        while(curr > q.r)
        {
            skloni(curr);
            curr--;
        }
        ans[q.idx] = get_ans();
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    preprocess();
    
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        //int s = 0;
       // for(int i=l;i<=r;i++) s+=a[i];
        //if(s==resiupit(l,r)) cout << "Ok\n";
        //else cout << "lose\n";
        //cout << resiupit(l,r) << "\n";
    }
    
    //moguce je da podrzava i update na jednom elementu funkcija update
    update(1,10);
    //kao i na segmentu ali je nezgodno pa je bolje da se za to koriste druge strukture
    
    
    
    
    return 0;
}
