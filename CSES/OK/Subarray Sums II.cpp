#include <bits/stdc++.h>

#define int long long

using namespace std;

map <int,int> mp;

signed main(){
    int n,x;
    cin>>n>>x;

    int a,sum=0,ans=0;
    mp[0]++;
    for(int i=0;i<n;i++){
        cin>>a;
        sum+=a;
        ans+=mp[sum-x];
        mp[sum]++;
    }
    cout<<ans<<"\n";
}

// reference from thanksone
