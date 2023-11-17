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
        for(int i=1;(1<<i)<=vis;i++) dp[i][(1<<i)+1]=G[0][i];// 因為底下略過了0所以要先初始化

        for(int i=1;i<=vis;i++){
            for(int j=n;j>0;j--){
                if( ((1<<j)&i)==0) continue;
                for(int k=1;(1<<k)<=i;k++){ // k不從0開始因為不能經過同一個點且一開始從0出發，所以不能包括0
                    if(k==j) continue;
                    if( ((1<<k)&i)!=0 && dp[j][i]!=0){
                        dp[j][i]=min(dp[j][i],dp[k][i-(1<<j)]+G[k][j]);
                    }else if( ((1<<k)&i)!=0 && dp[j][i]==0) dp[j][i]+=dp[k][i-(1<<j)]+G[k][j];
                }
            }
        }

        int ans=dp[1][(1<<n)-1]+G[1][0];
        for(int i=2;i<n;i++) ans=min(ans,dp[i][(1<<n)-1]+G[i][0]);
        for(int j=0;j<n;j++){
            for(int i=1;i<=vis;i++)
                cout<<dp[j][i]<<" \n"[i==vis];
        }

        cout<<ans<<endl;
        t--;
    }
}
