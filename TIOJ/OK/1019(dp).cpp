#include <bits/stdc++.h>

#define ll long long

using namespace std;

int const maxn=1500;

signed main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        ll pos[maxn];        
        for(int i=1;i<=n;i++) cin>>pos[i];
        ll dp[maxn];
        dp[1]=0, dp[2]=abs(pos[2]-pos[1]);
        for(int i=3;i<=n;i++) dp[i]=min(abs(pos[i]-pos[i-1])+dp[i-1], abs(pos[i]-pos[i-2])+dp[i-2]);
        cout<<dp[n]<<endl;
        t--;
    }
}