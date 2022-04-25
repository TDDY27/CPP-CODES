#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 8e18
#define int long long
using namespace std;

int t,n;
int num[150];
int pre[150];
int recdp[150][150];

int dp(int l,int r){
    if(recdp[l][r]!=0) return recdp[l][r];
    if(r<=l) return 0;
    else if(r-l==1) return num[l]+num[r];

    int lval,rval;
    int mmin=INF;
    int rec;
    int ans=0;
    for(int i=l;i<=r-1;i++){
        lval=dp(l,i);
        rval=dp(i+1,r);
        mmin=min(mmin,lval+rval);
    }
    ans=pre[r]-pre[l-1]+mmin;
    recdp[l][r]=ans;
    return ans;
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        memset(pre,0,sizeof(pre));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            cin>>num[i];
            pre[i]=num[i]+pre[i-1];
        }
        int ans;
        memset(recdp,0,sizeof(recdp));
        ans=dp(1,n);
        cout<<ans<<endl;
        t--;
    }
}
