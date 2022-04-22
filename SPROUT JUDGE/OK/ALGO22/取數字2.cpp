#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int t,n,k;
int const maxn=1e3+50;
int num[maxn];
int dp[maxn][2];

signed main(){
    TDDY
    cin>>t;

    while(t>0){
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>num[i];

        for(int i=1;i<=k;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=num[i];
        }

        for(int i=k+1;i<n+1;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            int temp=dp[i-k+1][0];
            for(int j=k; j<2*k,i-j>=1 ;j++)
                temp=max( {temp,dp[i-j][0],dp[i-j][1]} );
            dp[i][1]=temp+num[i];
        }

        cout<<max(dp[n][0],dp[n][1])<<endl;
        t--;
    }
}
