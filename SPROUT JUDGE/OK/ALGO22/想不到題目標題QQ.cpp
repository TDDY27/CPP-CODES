#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,k,q;
int const maxn=5e5+500;
int A[maxn];

int MT[maxn];
void mt19937_ing(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // random number generator
    shuffle(MT,MT+maxn,rng);
}

int times[maxn], rec[maxn], pre[maxn];

signed main(){
    TDDY
    cin>>n>>k>>q;

    for(int i=0;i<maxn;i++) MT[i]=i+7122;
    mt19937_ing();

    memset(times,0,sizeof times);
    pre[0]=0;

    for(int i=1;i<=n;i++){
        cin>>A[i];
        times[A[i]]++;
        if(times[A[i]]%k==0) rec[i]= -(k-1)*MT[A[i]];
        else rec[i]=MT[A[i]];

        pre[i]=pre[i-1]+rec[i];
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        if(pre[r]-pre[l-1]==0) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}
