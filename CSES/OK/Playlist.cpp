#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=2e5+500;
int s[maxn];
map <int,int> mp;

signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int now=0;
    int mmax=0;
    int rec=0;
    for(int i=1;i<=n;i++){
        if(!mp.count(s[i]) || mp[s[i]]<rec ){
            now++;
            mmax=max(mmax,now);
            mp[s[i]]=i;
        }else{
            now=i-mp[s[i]];
            rec=mp[s[i]];
            mp[s[i]]=i;
        }
    }
    cout<<mmax<<endl;
}
