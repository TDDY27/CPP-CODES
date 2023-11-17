#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int const maxn=2e5+500;
int srt[maxn];

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>srt[i];
    sort(srt,srt+n);

    int ans=1;
    for(int i=1;i<n;i++)
        if(srt[i]>srt[i-1]) ans++;
    cout<<ans<<endl;
}
