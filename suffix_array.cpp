#include <bits/stdc++.h> 

using namespace std;

//suffix array
//struktura koja sluzi da cuva sve sufikse 
//nekog stringa sortirane leksikografski
//konstrukcija objasnjena na codeforces edu 
//O(N log N)

struct suffar
{ 
	int n;
	string s;
	vector<int> p,c;

	suffar(string s)
	{
		s = s +"$";
		this->n = s.size();
		this->s = s;
	}

	void print()
	{
		for(int i = 0;i<n;i++) cout << p[i] << " ";
	}

	void counting_sort()
	{
		vector<int> cnt(n);
		for(int i = 0 ; i< n; i++)
		{
			int x = c[i];
			cnt[x]++;
		}

		vector<int> pn(n);
		vector<int> pos(n);
		pos[0] = 0;
		for(int i = 1;i<n;i++)
			pos[i] = pos[i-1] + cnt[i-1];

		for(int i = 0 ; i < n ; i++)
		{
			int x = p[i];
			int bl = c[x];
			pn[pos[bl]] = x;
			pos[bl]++;
		}
		p = pn;
	}

	void build()
	{
		p.reserve(n);
		c.reserve(n);
		vector<pair<char,int>> a(n);
		for(int i=0;i<n;i++) a[i] = {s[i],i};
		sort(a.begin(),a.end());

		for(int i = 0;i<n;i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i=1;i<n;i++)
		{
			if(a[i].first==a[i-1].first) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]] + 1;	
		}

		int k = 0;
		while((1 << k) < n)
		{
			for(int i=0; i<n; i++)
				p[i] = (p[i] - (1 << k) + n)%n;

			counting_sort();

			vector<int> cn(n);
			cn[p[0]] = 0;
			for(int i=1;i<n;i++)
			{
				pair<int,int> temp = {c[p[i]],c[(p[i] + (1 << k))%n]};
				pair<int,int> pre = {c[p[i-1]],c[(p[i-1] + (1 << k))%n]};
				if(temp == pre) cn[p[i]] = cn[p[i-1]];
				else cn[p[i]] = cn[p[i-1]] + 1;	
			}
			c = cn;
			k++;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);

	string s;
	cin >> s;
	suffar sf = suffar(s);
	sf.build();
	sf.print();

	return 0;
}