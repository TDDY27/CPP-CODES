#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

int const mod=1e9+7;

void solve(int n){
    int now=2;
    for(int i=2;i<=n;i++)
        now=now*2%mod;
    cout<<now;

}

signed main(){
    int n;
    cin>>n;
    solve(n);
}
