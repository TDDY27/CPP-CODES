#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

struct info{
    int n1=0, n2=0, n3=0;
    int lazt=0;
    bool res=0;
};

int const maxn=1e6+500;
int n,m;
info seg[maxn*4];

void update(int l,int r,int cur,int val,int Res){
    if(Res){
        seg[cur].n1=r-l+1;
        seg[cur].n2=0, seg[cur].n3=0;
    }
    seg[cur].res=Res;

    val%=3;
    int tmp=val;
    while(tmp--){
        swap(seg[cur].n1, seg[cur].n2);
        swap(seg[cur].n1, seg[cur].n3);
    }
    seg[cur].lazt+=val, seg[cur].lazt%=3;
}

void push(int l,int r,int cur){
    int mid=(l+r)/2;
    update(l,mid,cur*2, seg[cur].lazt, seg[cur].res);
    update(mid+1,r,cur*2+1, seg[cur].lazt, seg[cur].res);
    seg[cur].lazt=0, seg[cur].res=0;
}

void pull(int cur){
    seg[cur].n1=seg[cur*2].n1+seg[cur*2+1].n1;
    seg[cur].n2=seg[cur*2].n2+seg[cur*2+1].n2;
    seg[cur].n3=seg[cur*2].n3+seg[cur*2+1].n3;
}

void turn(int l,int r,int ql,int qr,int cur){
    if(l>qr || r<ql) return;
    if(ql<=l && r<=qr ){ update(l,r,cur,1,0); return; }

    int mid=(l+r)/2;
    push(l,r,cur);
    turn(l,mid,ql,qr,cur*2), turn(mid+1,r,ql,qr,cur*2+1);
    pull(cur);
}

void reset(int l,int r,int ql,int qr,int cur){
    if(l>qr || r<ql) return;
    if(ql<=l && r<=qr ){ update(l,r,cur,0,1); return; }

    int mid=(l+r)/2;
    push(l,r,cur);
    reset(l,mid,ql,qr,cur*2), reset(mid+1,r,ql,qr,cur*2+1);
    pull(cur);
}

int query(int l,int r,int ql,int qr,int cur){
    if(l>qr || r<ql) return 0;
    if(ql<=l && r<=qr ) return seg[cur].n1;
    int mid=(l+r)/2;
    push(l,r,cur);
    return query(l,mid,ql,qr,cur*2)+query(mid+1,r,ql,qr,cur*2+1);
}

void build(int l,int r,int cur){
    if(l>=r){ seg[cur].n1=1; return; }

    int mid=(l+r)/2;
    build(l,mid,cur*2), build(mid+1,r,cur*2+1);
    seg[cur].n1=seg[cur*2].n1+seg[cur*2+1].n1;
}


signed main(){
    TDDY
    cin>>n>>m;

    build(1,n,1);
    string Q;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>Q>>a>>b;
        if(Q[0]=='T') turn(1,n,a,b,1);
        else if(Q[0]=='R') reset(1,n,a,b,1);
        else cout<<query(1,n,a,b,1)<<endl;
        //cout<<seg[1].n1<<" "<<seg[1].n2<<" "<<seg[1].n3<<endl;
        //cout<<seg[2].n1<<" "<<seg[2].n2<<" "<<seg[2].n3<<endl;
        //cout<<seg[3].n1<<" "<<seg[3].n2<<" "<<seg[3].n3<<endl;
    }

}
