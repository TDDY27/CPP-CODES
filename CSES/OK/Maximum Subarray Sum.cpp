#include <bits/stdc++.h>
#define _INF -1e17
#define int long long

using namespace std;

int const maxn=2e5+500;
int num[maxn];

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];

    int now=0,mmax=_INF,rec=_INF;
    for(int i=0;i<n;i++){
        now+=num[i];
        if(now<0) now=0;
        mmax=max(mmax,now);
        rec=max(rec,num[i]);
    }
    if(rec<0) cout<<rec<<endl;
    else cout<<mmax<<endl;
}
