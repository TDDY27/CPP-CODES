#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 9e17
#define int long long

using namespace std;

int n;
int G[150][150];
int dp[150][150];

signed main(){
    TDDY
    while(cin>>n && n){
        for(int i=0;i<150;i++)
            for(int j=0;j<150;j++){ G[i][j]=INF; dp[i][j]=INF; }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int tw; cin>>tw;
                if(tw){ G[i][j]=tw; dp[i][j]=tw; }
            }
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        int ans=INF;
        for(int i=1;i<=n;i++) ans=min(ans,dp[i][i]);
        if(ans==INF) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }

}
