#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

int n,a,b,k;
int dp[2100][2100];
int const mod=1e9+7;

int strt(){
    if(b>a) return 1;
    else return b+1;
}

int End(){
    if(b>a) return b-1;
    else return n;
}

int dis(int pos){
    return abs(pos-b);
}

signed main(){
    TDDY
    memset(dp,0,sizeof dp);

    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    int rec[2100];
    for(int i=1;i<=k;i++){
        memset(rec,0,sizeof rec);
        for(int j=strt();j<=End();j++){
            if(j-dis(j)+1-1>0) rec[j-dis(j)+1-1]-=dp[i-1][j];

            if(j+dis(j)-1<=n) rec[j+dis(j)-1]+=dp[i-1][j];
            else rec[n]+=dp[i-1][j];

            dp[i][j]-=dp[i-1][j];
            dp[i][j]%=mod;
        }

        int now=0;
        for(int j=n;j>=1;j--){
            now+=rec[j];
            //now%=mod;
            dp[i][j]+=now;
            dp[i][j]%=mod;
        }
    }

    int sum=0;
    for(int i=1;i<=n;i++){ sum+=dp[k][i]; sum%=mod;}
    cout<<sum<<endl;
}
