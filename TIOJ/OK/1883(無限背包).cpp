#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

int t,w,b,n,m;
int A[1500],D[1500];
int dp[10500];

int res(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j-A[i]>0 && dp[j-A[i]]!=0) dp[j]=max(dp[j],dp[j-A[i]]+D[i]);
            else if(j-A[i]==0) dp[j]=max(dp[j],D[i]);

            if(dp[j]>=b && j!=w) return 1;
        }
    }
    return 0;
}


signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(dp,0,sizeof dp);
        memset(A,0,sizeof A);
        memset(D,0,sizeof D);
        cin>>w>>b>>n;
        for(int i=1;i<=n;i++) cin>>A[i]>>D[i];
        cin>>m;
        for(int i=1;i<=n;i++) A[i]+=m;

        int ans=res();
        if(ans==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        t--;
    }
}
