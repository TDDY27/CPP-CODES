#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n;
int const mod=1000007 ;
int const maxn=1e5+5000;
int dp[maxn];

signed main(){
    TDDY
    cin>>t;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[2]=3;
    int pre=0;
    for(int i=4;i<=maxn;i+=2){
        pre+=dp[i-4];
        dp[i]+=dp[i-2]*3;
        dp[i]+=pre*2;
        pre%=mod;
        dp[i]%=mod;
    }


    while(t>0){
        cin>>n;
        cout<<dp[n]<<endl;
        t--;
    }
}
