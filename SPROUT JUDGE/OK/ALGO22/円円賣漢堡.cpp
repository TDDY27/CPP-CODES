#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
#define PF push_front
#define INF 1e8

using namespace std;
int t,n,k,c;
int const maxn=1e5+500;
int val[maxn];

struct info{
    int pos;
    int sum;
};

deque <info> dan;
info dp[maxn];

signed main(){
    cin>>t;
    while(t>0){
        dan.clear();
        memset(dp,0,sizeof dp);
        memset(val,0,sizeof val);

        cin>>n>>k>>c;
        for(int i=1;i<=n;i++) cin>>val[i];

        for(int i=1;i<=n;i++){
            while( dan.size()>0 && (i-dan.front().pos)>k) dan.pop_front();

            if(dan.size()>0) dp[i].sum=val[i]-c*i+dan.front().sum;
            dp[i].sum=max(dp[i].sum,val[i]); //because of dan.front().sum-c*i may <0
            dp[i].sum+=c*i;
            dp[i].pos=i;

            while( dan.size()>0 && dp[i].sum>=dan.back().sum) dan.pop_back();
            if(dp[i].sum>0 ) dan.PB(dp[i]);

            dp[i].sum-=c*i;
            //cout<<dp[i].sum<<" "<<dp[i].pos<<endl;
            //if(dan.size()>0) cout<<dan.back().sum<<" "<<dan.back().pos<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i].sum);
        cout<<ans<<endl;
        t--;
    }
}
