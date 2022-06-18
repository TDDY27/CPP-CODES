#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define _INF -9e17

using namespace std;

struct info{
    int sum;//the integral sum
    int mlr;//the maximum from left to right
    int mrl;//the maximum from right to left
    int mmax;// the max consecutive ones
};

int n,q;
int const maxn=1e5+500;
info seg[maxn*4];
int num[maxn];

info query(int l,int r,int ql,int qr,int cur){
    info no; no.mmax=_INF;
    if(l>qr || r<ql) return no;
    if(ql<=l && r<=qr) return seg[cur];

    int mid=(l+r)/2;
    info ll,rr;
    ll=query(l,mid,ql,qr,cur*2), rr=query(mid+1,r,ql,qr,cur*2+1);
    if(ll.mmax==_INF && rr.mmax==_INF) return no;
    else if(ll.mmax==_INF && rr.mmax!=_INF) return rr;
    else if(ll.mmax!=_INF && rr.mmax==_INF) return ll;

    info tmp;
    tmp.mmax=max({ ll.mmax, rr.mmax, ll.mrl+rr.mlr });
    tmp.mlr=max( ll.mlr, ll.sum+rr.mlr);
    tmp.mrl=max( rr.mrl, rr.sum+ll.mrl);
    tmp.sum=rr.sum+ll.sum;
    return tmp;
}

void build(int l,int r,int cur){
    if(l>=r){
        seg[cur].mlr=num[l];
        seg[cur].mrl=num[l];
        seg[cur].mmax=num[l];
        seg[cur].sum=num[l];
        return;
    }

    int mid=(l+r)/2;
    build(l,mid,cur*2), build(mid+1,r,cur*2+1);

    seg[cur].mmax=max({ seg[cur*2].mmax, seg[cur*2+1].mmax, seg[cur*2].mrl+seg[cur*2+1].mlr });
    seg[cur].mlr=max( seg[cur*2].mlr, seg[cur*2].sum+seg[cur*2+1].mlr );
    seg[cur].mrl=max( seg[cur*2+1].mrl, seg[cur*2+1].sum+seg[cur*2].mrl );
    seg[cur].sum=seg[cur*2].sum+seg[cur*2+1].sum;
}

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>num[i];

    build(1,n,1);
    int QL,QR,ans;
    for(int i=0;i<q;i++){
        cin>>QL>>QR;
        ans=query(1,n,QL,QR,1).mmax;
        if(ans>=0) cout<<ans<<endl;
        else cout<<0<<endl;
    }
}
