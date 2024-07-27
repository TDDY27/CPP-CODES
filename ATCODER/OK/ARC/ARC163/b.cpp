#include <bits/stdc++.h>
// #include <array>

using namespace std;

#define ll long long
ll const maxn=2e5+500;
ll const INF=2e9+100;

signed main(){
    int n,m;
    cin>>n>>m;
    int a[maxn];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+3,a+n+1);
    // for(int i=1;i<)
    int ans=INF;
    for(int i=3;i+m-1<=n;i++){
        int tmp=0;
        if(a[i+m-1]>a[2]) tmp+=a[i+m-1]-a[2];
        if(a[i]<a[1]) tmp+=a[1]-a[i];
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}

// signed main(){
//     int n,m;
//     cin>>n>>m;
//     ll a[maxn];
//     for(int i=1;i<=n;i++) cin>>a[i];
//     ll first=a[1], second=a[2];
//     ll recfir[maxn]; // record first
//     ll recsec[maxn]; // record second
//     int firnow=1, secnow=1;
//     fill(recfir,recfir+maxn,INF);
//     fill(recsec,recsec+maxn,INF);
//     if(first>second)
//     for(int i=3;i<=n;i++){
//         if(a[i]>=a[1] && a[i]<=a[2]) m--;
//         else if(a[i]>a[2]) recsec[secnow++]=a[i]-a[2];
//         else if(a[i]<a[1]) recfir[firnow++]=a[1]-a[i];
//     }
//     sort(recfir+1,recfir+firnow);
//     sort(recsec+1,recsec+secnow);
    
//     recfir[0]=0, recsec[0]=0;
//     if(m<=0) cout<<0<<endl;
//     else{
//         ll ans=INF;
//         // cout<<"recfir+recsec"<<endl;
//         for(int i=0;i<=m;i++){
//             if(i<firnow && m-i<secnow ) ans=min(ans,recfir[i]+recsec[m-i]);
//             // cout<<recfir[i]+recsec[m-(i+1)-1]<<" ";
//         }
//         // cout<<endl;
//         cout<<ans<<endl;
//     }
// }