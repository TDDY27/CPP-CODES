#include <bits/stdc++.h>

using namespace std;

int const maxn=5005;

signed main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='p'){
            start=i;
            break;
        }
    }
    if(start==-1){
        cout<<s<<endl;
        return 0;
    }
    
    string rec[maxn];
    for(int i=0;i<maxn;i++) rec[i]=s;
    int now=0;
    int index=start;
    for(int i=n-1;i>=start;i--){
        for(int j=i;j>=start;j--){
            if(s[j]=='p') rec[now][index++]='d';
            else rec[now][index++]='p';
        }
        now++;
        index=start;
    }
    sort(rec,rec+now);
    cout<<rec[0]<<endl;
    // for(int i=0;i<rec[0].size();i++) s[start++]=rec[0][i];
    // cout<<s<<endl;

    // for(int i=0;i<now;i++){
    //     cout<<rec[i]<<endl;
    //     cout<<rec[i].size()<<endl;
    // }
}