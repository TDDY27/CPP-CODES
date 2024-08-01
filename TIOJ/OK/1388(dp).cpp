#include <bits/stdc++.h>

#define ll long long

using namespace std;

int const maxn=110;

 ll solve(int l,int r,ll slime[],vector<vector<ll>> &dp){
    if(l==r) return slime[l];
    if(dp[l][r]!=-1) return dp[l][r];
    for(int i=l;i<r;i++){
        if( (r-l+1)%2==0) dp[l][r]=max(dp[l][r], solve(l,i,slime,dp)+solve(i+1,r,slime,dp));
        else dp[l][r]=max(dp[l][r], solve(l,i,slime,dp)*solve(i+1,r,slime,dp));
    }
    return dp[l][r];
}

signed main(){
    int n;
    while(cin>>n){
        ll slime[maxn];
        for(int i=1;i<=n;i++) cin>>slime[i];
        vector<vector<ll>> dp(maxn,vector<ll>(maxn,-1));
        cout<<solve(1,n,slime,dp)<<endl;
    }    
}