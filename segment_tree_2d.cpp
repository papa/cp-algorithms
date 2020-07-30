#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//2D segmentno stablo
//build radi u slozenosti O(n*m)
//sum O(log(n)*log(m))
//update isto kao sum

struct segment_tree_2d
{
    int n,m;
    vector<vector<ll> > seg;
    vector<vector<ll> > a;

    segment_tree_2d(int n,int m)
    {
        this->n = n;
        this->m = m;
        seg.resize(4*(n+5));
        for(int i=0;i<4*(n+5);i++) seg[i].resize(4*(m+5));
    }

    void build_y(int idx,int lx,int rx,int idy,int ly,int ry)
    {
        if(ly==ry)
        {
            if(lx==rx) seg[idx][idy] = a[lx][ly];
            else seg[idx][idy] = seg[2*idx][idy] + seg[2*idx+1][idy];
        }
        else
        {
            int my = (ly+ry)/2;
            build_y(idx,lx,rx,2*idy,ly,my);
            build_y(idx,lx,rx,2*idy+1,my+1,ry);
            seg[idx][idy] = seg[idx][2*idy] + seg[idx][2*idy+1];
        }
    }

    void build_x(int idx,int lx,int rx)
    {
        if(lx!=rx)
        {
            int mx = (lx+rx)/2;
            build_x(2*idx,lx,mx);
            build_x(2*idx+1,mx+1,rx);
        }
        build_y(idx,lx,rx,1,1,m);
    }
    
    ll sum_y(int idx,int idy,int tly,int try_,int ly,int ry)
    {
        if(ly > ry) return 0LL;
        if(ly==tly && ry ==try_) return seg[idx][idy];
        int tmy = (tly + try_)/2;
        return sum_y(idx,2*idy,tly,tmy,ly,min(ry,tmy))
                + sum_y(idx,2*idy+1,tmy+1,try_,max(ly,tmy+1),ry);
    }
    
    ll sum_x(int idx,int tlx,int trx,int lx,int rx,int ly,int ry)
    {
        if(lx > rx) return 0LL;
        if(lx==tlx && trx==rx) return sum_y(idx,1,1,m,ly,ry);
        int tmx = (tlx+trx)/2;
        return sum_x(2*idx,tlx,tmx,lx,min(rx,tmx),ly,ry)
               + sum_x(2*idx+1,tmx+1,trx,max(lx,tmx+1),rx,ly,ry);
    }
    
    void update_y(int idx,int lx,int rx,int idy,int ly,int ry,int x,int y,int v)
    {
        if(ly==ry)
        {
            if(lx==rx) seg[idx][idy] = v;
            else seg[idx][idy] = seg[2*idx][idy] + seg[2*idx+1][idy];
        }
        else
        {
            int my = (ly+ry)/2;
            if(y<=my) update_y(idx,lx,rx,2*idy,ly,my,x,y,v);
            else update_y(idx,lx,tx,2*idy+1,my+1,ry,x,y,v);
            seg[idx][idy] = seg[idx][2*idy] + seg[idx][2*idy+1];
        } 
    }
    
    void update_x(int idx,int lx,int rx,int x,int y,int v)
    {
        if(lx!=rx)
        {
            int mx = (lx+rx)/2;
            if(x<=mx) update_x(2*idx,lx,mx,x,y,v);
            else update_x(2*idx+1,mx+1,rx,x,y,v);
        }
        update_y(id,lx,rx,1,1,m,x,y,v);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);



    return 0;
}
