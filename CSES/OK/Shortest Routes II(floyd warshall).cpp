#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);
#define INF 9e17
#define int long long

using namespace std;

int n,m,q;
int G[550][550];
int dp[550][550];

signed main(){
    TDDY
    for(int i=0;i<550;i++)
    for(int j=0;j<550;j++){ G[i][j]=INF; dp[i][j]=INF; }

    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int tu,tv,tw;
        cin>>tu>>tv>>tw;
        G[tu][tv]=min(G[tu][tv],tw); G[tv][tu]=min(G[tv][tu],tw);
        dp[tu][tv]=G[tu][tv]; dp[tv][tu]=G[tv][tu]; // there maybe two or more road connect the same city
    }
    for(int i=0;i<550;i++) dp[i][i]=0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++){
        int tu,tv;
        cin>>tu>>tv;
        if(dp[tu][tv]==INF) cout<<-1<<endl;
        else cout<<dp[tu][tv]<<endl;
    }
}
