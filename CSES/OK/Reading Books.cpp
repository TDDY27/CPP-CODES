#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n,t;
    int sum=0,mmax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        sum+=t;
        mmax=max(mmax,t);
    }
    sum-=mmax;
    if(sum<mmax) cout<<mmax*2;
    else cout<<sum+mmax<<endl;
}
// reference from thanksone
