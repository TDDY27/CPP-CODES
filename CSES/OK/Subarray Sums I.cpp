#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=2e5+500;
int arr[maxn];

signed main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,r=0,sum=arr[0],ans=0;
    while(r<n){
        if(sum==x) ans++;
        r++;
        sum+=arr[r];
        while(sum>x && l<r) sum-=arr[l++];
    }
    cout<<ans<<endl;
}
