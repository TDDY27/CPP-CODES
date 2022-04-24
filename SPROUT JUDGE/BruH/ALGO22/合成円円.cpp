#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int t,n;
int num[150];
int pre[150];
int ans=0;

void dp(int l,int r){
    if(r<=l){
        return ;
    }else if(r-l==1){
        ans+=num[l]+num[r];
        return ;
    }

    int loc=l;
    int mmin= abs( num[l]-(pre[r]-pre[l]) );
    for(int i=l+1;i<=r-1;i++){
        int temp= abs( pre[i]-pre[l-1]-(pre[r]-pre[i]) );
        if( temp<mmin){
            loc=i;
            mmin=temp;
        }
    }
    ans+=pre[r]-pre[l-1];
    dp(l,loc);
    dp(loc+1,r);
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        ans=0;
        memset(pre,0,sizeof(pre));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            cin>>num[i];
            pre[i]=num[i]+pre[i-1];
        }
        dp(1,n);
        cout<<ans<<endl;
        t--;
    }
}
