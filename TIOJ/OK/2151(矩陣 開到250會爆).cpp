#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define matrix array< array<int,210> ,210>

using namespace std;

int n,m,s,t;
array<int ,210> fav;
int const INF=-1e18;
matrix G;

matrix mul(matrix A,matrix B){
    matrix res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[i][j]=INF;
            for(int k=1;k<=n;k++){
                res[i][j]=max(res[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return res;
}

matrix exp(matrix A,int T){
    matrix res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) res[i][j]=INF;
        res[i][i]=0;
    }

    for(int i=1;i<=T;i<<=1){
        if(i&T) res=mul(res,A);
        A=mul(A,A);
    }
    return res;
}


signed main(){
    TDDY
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++) cin>>fav[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) G[i][j]=INF;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u][v]=fav[v];
    }
    G=exp(G,t);
    int ans=INF;
    for(int i=1;i<=n;i++) ans=max(ans,G[s][i]);
    cout<<ans<<endl;
}
