#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

int t,n;
int G[500][500];
int dp[20][100000];

signed main(){
    cin>>t;
    while(t>0){
        memset(G,0,sizeof G);
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tmp;
                cin>>tmp;
                G[i][j]=tmp;
                G[j][i]=tmp;
            }
        }

        memset(dp,0,sizeof(dp));
        int vis=(1<<n)-1;
        for(int i=1;i<=vis;i++){
            for(int j=0;j<n;j++){
                if( (1<<j)&i==0) continue;
                for(int k=0;(1<<k)<=i;k++){
                    if(k==j) continue;
                    if( (1<<k)&i!=0 && dp[j][i]!=0) dp[j][i]=min(dp[j][i],dp[k][i-(1<<j)]+G[k][j]);
                    else if( (1<<k)&i!=0 && dp[j][i]==0) dp[j][i]=dp[k][i-(1<<j)]+G[k][j];
                }
            }
        }

        cout<<dp[0][1<<n-1]<<endl;
        t--;
    }
}
