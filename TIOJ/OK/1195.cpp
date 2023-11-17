#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int n;
string s;

signed main(){
    TDDY
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>s;
        int len=s.size();
        int rec=1,mmax=0;
        for(int j=len-3;j<len;j++){
            if(s[j]==s[j-1]) rec++;
            else rec=1;
            mmax=max(mmax,rec);
        }
        if(mmax==4) ans+=2000;
        else if(mmax==3) ans+=1000;
        else if(s[len-4]==s[len-3] && s[len-2]==s[len-1] && s[len-4]!=s[len-2]) ans+=1500;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
