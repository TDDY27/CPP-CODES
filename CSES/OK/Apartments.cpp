#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,m,k;
int const maxn=2e5+500;
int app[maxn];
int apa[maxn];

signed main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>app[i];
    for(int i=0;i<m;i++) cin>>apa[i];

    sort(app,app+n);
    sort(apa,apa+m);
    int na=0,nb=0,ans=0;
    while(na<n && nb<m){
        if( apa[nb]>=app[na]-k && apa[nb]<=app[na]+k) ans++, na++, nb++;
        else if( apa[nb]>app[na]+k) na++;
        else if( apa[nb]<app[na]-k) nb++;
    }
    cout<<ans<<endl;
}
