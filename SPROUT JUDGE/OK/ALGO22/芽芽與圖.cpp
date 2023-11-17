#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define matrix array<array<int,150>,150>
using namespace std;

int const mod=1e9+7;
int n,m,l;
matrix AM; //adjacency matrix
matrix dp;

matrix mul(matrix a,matrix b){
    matrix T;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            T[i][j]=0;
            for(int k=1;k<=n;k++){
                T[i][j]=(T[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return T;
}

matrix exp(matrix a){
    matrix res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) res[i][j]=0;
        res[i][i]=1;
    }
    for(int i=1;i<=l; i<<=1){
        if(i&l) res=mul(res,a);
        a=mul(a,a);
    }
    return res;
}


signed main(){
    TDDY
    cin>>n>>m>>l;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        AM[u][v]=1;
    }
    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<AM[i][j]<<" \n"[j==n];*/

    dp=exp(AM);

    for(int i=1;i<=n;i++){
            cout<<dp[i][1];
        for(int j=2;j<=n;j++){
            cout<<" "<<dp[i][j];
        }
        cout<<endl;
    }

}
