#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
using namespace std;

int n;
int const maxn=1e6+50;
int const mod=10000019;
int a[maxn];
queue <int> que;

int ans=0;
void solve(int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int now1,now2;
    now1=l;
    now2=mid+1;

    int add=0;
    for(int i=l;i<=r;i++){
        if( (a[now1]<=a[now2] || now2>r) && now1<=mid){
            que.push(a[now1]);
            ans+=(a[now1]%mod)*add%mod;
            now1++;
        }else{
            add++;
            que.push(a[now2]);
            ans+=(a[now2]%mod)*( (mid-now1+1)%mod)%mod;
            now2++;
        }
        ans%=mod;
    }

    for(int i=l;i<=r;i++){
        a[i]=que.front();
        que.pop();
    }
}


signed main(){
    TDDY
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve(1,n);
    cout<<ans%mod;
    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    //cout<<endl;
}
