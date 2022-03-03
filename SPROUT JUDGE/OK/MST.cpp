#include <bits/stdc++.h>
#define int long long
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=3e5+500;
int f[maxn];
int sz[maxn];

struct mst {int u,v,w; };
mst G[maxn];

bool cmp(mst a,mst b) { return a.w<b.w; }

int fa(int a){
    if(f[a]==a) return a;
    f[a]=fa(f[a]);
    return f[a];
}

void comb(int a,int b){
    int A=fa(a),B=fa(b);
    if(sz[A]>=sz[B]){
        sz[A]+=sz[B];
        f[B]=A;
    }else{
        sz[B]+=sz[A];
        f[A]=B;
    }
}

signed main(){
    TDDY
    int n,m;
    cin>>n>>m;
    fill(sz,sz+n+10,1);
    memset(G,0,sizeof(G));
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++) cin>>G[i].u>>G[i].v>>G[i].w;
    sort(G,G+m,cmp);

    int ans=0;
    for(int i=0;i<m;i++){
        if(fa(G[i].u)==fa(G[i].v)) continue;
        ans+=G[i].w;
        comb(G[i].u,G[i].v);
    }
    cout<<ans<<endl;
}
