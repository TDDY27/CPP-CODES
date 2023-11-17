#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n;
int const mod=1000007;
int const maxn=1e5+5000;
int dpr[maxn][5];
int dpgb[maxn][5];

signed main(){
    TDDY
    cin>>t;
    // 1:red 2:green 3:blue
    memset(dpr,0,sizeof(dpr));
    memset(dpgb,0,sizeof(dpgb));

    dpr[2][1]=1;
    dpr[2][2]=1;
    dpr[2][3]=1;
    for(int i=3;i<maxn;i++){
        dpr[i][1]+=( dpr[i-1][1]+dpr[i-1][2]+dpr[i-1][3] )%mod;
        dpr[i][2]+=( dpr[i-1][1]+dpr[i-1][2] )%mod;
        dpr[i][3]+=( dpr[i-1][1]+dpr[i-1][3] )%mod;
    }

    dpgb[2][1]=1;
    dpgb[2][2]=1;
    dpgb[2][3]=0;
    for(int i=3;i<maxn;i++){
        dpgb[i][1]+=( dpgb[i-1][1]+dpgb[i-1][2]+dpgb[i-1][3] )%mod;
        dpgb[i][2]+=( dpgb[i-1][1]+dpgb[i-1][2] )%mod;
        dpgb[i][3]+=( dpgb[i-1][1]+dpgb[i-1][3] )%mod;
    }
    while(t>0){
        cin>>n;
        int ans=0;
        ans+=dpr[n][1]+dpr[n][2]+dpr[n][3];
        ans+=( dpgb[n-1][1]+dpgb[n-1][2]+dpgb[n-1][3] )*2%mod;
        ans+=( dpgb[n-1][1]+dpgb[n-1][2] )*2%mod;
        ans%=mod;
        if(n==1) cout<<3<<endl;
        else if(n==2) cout<<7<<endl;
        else cout<<ans<<endl;
        t--;
    }
}
