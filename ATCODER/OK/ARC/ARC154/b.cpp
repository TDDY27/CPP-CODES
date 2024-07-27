#include <bits/stdc++.h>

using namespace std;

signed main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int rec[30];
    fill(rec,rec+30,0);
    for(int i=0;i<n;i++){
        rec[s[i]-'a']++;
        rec[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(rec[i]!=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    int now=n-1;
    for(int i=n-1;i>=0;i--) if(t[i]==s[now]) now--;
    cout<<now+1<<endl;
}
