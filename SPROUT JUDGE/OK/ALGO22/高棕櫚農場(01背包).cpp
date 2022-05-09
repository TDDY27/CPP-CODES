#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 1e9+7
using namespace std;

int t,n,m;
int const maxn=1e6+500;
int sat[150];
int ful[150];
int dp[maxn];


signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(sat,0,sizeof(sat));
        memset(ful,0,sizeof(ful));
        fill(dp,dp+maxn,INF);
        cin>>n>>m;

        int V=0;
        for(int i=1;i<=n;i++){
            cin>>ful[i]>>sat[i];
            V+=sat[i];
        }


        for(int i=1;i<=n;i++){
            for(int j=V;j>=0;j--)
                if(j-sat[i]>0) dp[j]=min(dp[j],dp[j-sat[i]]+ful[i]);
                else if(j-sat[i]==0) dp[j]=min(dp[j],ful[i]);
        }

        int rec;
        for(int i=1;i<=V;i++)
            if(dp[i]<=m) rec=i;
        cout<<rec<<endl;


        t--;
    }
}
