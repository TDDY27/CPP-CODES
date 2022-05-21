#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    TDDY
    string s;
    while(getline(cin,s)){
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
            else if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
            else s[i]=' ';
        }
        for(int i=0;i<len;i++){
            if(s[i]!=' ') cout<<s[i];
            else if(s[i]==' ' && s[i+1]!=' ') cout<<s[i];
        }
        cout<<endl;
    }
}
