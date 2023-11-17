#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int t,n;
int const maxn=1e5+500;
int num[maxn];
int dp[maxn][2];

signed main(){
    TDDY
    cin>>t;

    while(t>0){
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        dp[1][0]=0;
        dp[1][1]=num[1];
        for(int i=2;i<maxn;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=max( {dp[i-1][0],dp[i-2][0],dp[i-2][1]} )+num[i];
        }

        cout<<max(dp[n][0],dp[n][1])<<endl;
        t--;
    }
}
