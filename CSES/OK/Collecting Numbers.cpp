#include <bits/stdc++.h>

using namespace std;

int const maxn=2e5+500;
int srt[maxn];

signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        srt[tmp]=i;
    }

    int ans=1;
    for(int i=1;i<=n-1;i++)
        if(srt[i+1]<srt[i]) ans++;
    cout<<ans<<endl;
}
