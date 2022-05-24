#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,m;
unordered_map <string,int> mp;

signed main(){
    TDDY
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(!mp.count(s)) mp[s]=1;
        else{ int tmp=mp[s]; mp[s]=tmp+1; }
    }
    for(int i=0;i<m;i++){
        cin>>s;
        if(mp.count(s)) cout<<mp[s]<<endl;
        else cout<<0<<endl;
    }
}
