#include <bits/stdc++.h>

#define int long long

using namespace std;

int const maxn=2e5+500;
int k[maxn];

int mch(int n,int t){
    int sum=0;
    for(int i=0;i<n;i++) sum+=t/k[i];
    return sum;
}

int BS(int n,int t){
    int l=0, r=1e18/n+1e9, mid;
    while(l<r){
        mid=(l+r)/2;
        if(mch(n,mid)<t) l=mid+1;
        else r=mid;
    }
    return l;
}

signed main(){
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>k[i];
    cout<<BS(n,t);
}
