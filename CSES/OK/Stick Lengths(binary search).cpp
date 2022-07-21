#include <bits/stdc++.h>
#define int long long
#define INF 1e17

using namespace std;

int const maxn=2e5+500;
int num[maxn];

int cost(int n,int val){
    int sum=0;
    for(int i=1;i<=n;i++) sum+=labs(num[i]-val);
    return sum;
}

int BS(int n){
    int l=1, r=1e9, mid;
    while(l<r){
        mid=(l+r)/2;
        if(cost(n,mid)<cost(n,mid+1)) r=mid;
        else l=mid+1;
    }
    return cost(n,l);
}

signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num+1,num+n+1);

    cout<<BS(n)<<endl;
}
