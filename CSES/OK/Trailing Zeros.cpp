#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;


void solve(int n){
    int cnt2=0, cnt5=0;

    for(int i=2;i<=n;i*=2) cnt2+=(n/i);
    for(int i=5;i<=n;i*=5) cnt5+=(n/i);
    cout<<min(cnt2,cnt5)<<endl;
}

signed main(){
    int n;
    cin>>n;
    solve(n);
}
