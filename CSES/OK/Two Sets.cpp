#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;


int const maxn=1e6+500;
int vis[maxn];


void solve(int n){
    int tot=(1+n)*n/2;
    if(tot%2){ cout<<"NO"<<endl; return; }
    else cout<<"YES"<<endl;

    int cnt=0,sum=0;
    for(int i=n;i>0;i--){
        if(sum< tot/2){
            cnt++;
            sum+=i;
            vis[i]=1;
        }
        if(sum> tot/2){
            cnt--;
            sum-=i;
            vis[i]=0;
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
        if(vis[i]) cout<<i<<" ";
    cout<<endl;

    cout<<n-cnt<<endl;
    for(int i=1;i<=n;i++)
        if(!vis[i]) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    int n;
    cin>>n;
    solve(n);
}
