#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,t;
int const maxn=1e6+500;
int seg[maxn*4];
int num[maxn];

void modify(int l,int r,int cur,int pos,int val){
    if(l>=r){ seg[cur]=val; return; }
    int mid=(l+r)/2;
    if(pos<=mid) modify(l,mid,cur*2,pos,val);
    else modify(mid+1,r,cur*2+1,pos,val);
    seg[cur]=min(seg[cur*2],seg[cur*2+1]);
}

int query(int l,int r,int ql,int qr,int cur){
    if(l>qr || r<ql) return maxn;
    if(ql<=l && r<=qr) return seg[cur];
    int mid=(l+r)/2;
    return min( query(l,mid,ql,qr,cur*2), query(mid+1,r,ql,qr,cur*2+1) );
}

void build(int l,int r,int cur){
    if(l>=r){ seg[cur]=num[l]; return; }
    int mid=(l+r)/2;
    build(l,mid,cur*2), build(mid+1,r,cur*2+1);
    seg[cur]=min(seg[cur*2], seg[cur*2+1]);
}

signed main(){
    TDDY
    cin>>t>>n;
    for(int i=1;i<=n;i++) cin>>num[i];

    build(1,n,1);
    int q,x,y;
    for(int i=0;i<t;i++){
        cin>>q>>x>>y;
        if(q==1) cout<<query(1,n,x+1,y+1,1)<<endl;
        else modify(1,n,1,x+1,y);
    }

}
