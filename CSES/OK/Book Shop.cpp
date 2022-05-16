#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define int long long
using namespace std;

int n,x;
int const maxn=1e5+500;
int dp[maxn];
int pri[1500];
int pag[1500];

signed main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>pri[i];
    for(int i=1;i<=n;i++) cin>>pag[i];

    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=x;j>=1;j--){
            if(j-pri[i]>0 && dp[j-pri[i]]!=0) dp[j]=max(dp[j],dp[j-pri[i]]+pag[i]);
            else if(j-pri[i]==0) dp[j]=max(dp[j],pag[i]);
        }
    }

    int ans=0;
    for(int i=1;i<=x;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
