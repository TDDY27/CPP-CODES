#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF -1e9
//#define int long long
using namespace std;

int t,n,m,sum;
int sat[150];
int ful[150];
int dp[1500][150];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(sat,0,sizeof sat);
        memset(ful,0,sizeof ful);
        memset(dp,0,sizeof dp);
        cin>>n>>m>>sum;

        for(int i=1;i<=n;i++) cin>>ful[i]>>sat[i];

        for(int i=1;i<=n;i++){
            for(int j=m;j>0;j--){
                for(int k=sum;k>0;k--){
                    if(j-ful[i]>0 && k-1>0){
                        if(dp[j-ful[i]][k-1]>0) dp[j][k]=max(dp[j][k],dp[j-ful[i]][k-1]+sat[i]);
                    }else if(j-ful[i]==0 && k-1==0){
                        dp[j][k]=sat[i];
                    }
                }
            }
        }

        int res=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=sum;j++) res=max(res,dp[i][j]);
        cout<<res<<endl;
        t--;
    }
}
