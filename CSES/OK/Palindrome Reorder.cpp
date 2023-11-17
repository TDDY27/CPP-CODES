#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

unordered_map <char,int> rec;

signed main(){
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(!rec.count(s[i]) ) rec[s[i]]=1;
        else rec[s[i]]++;
    }

    vector<char> vec;
    int flag=0;
    char odd=0;
    int vis[30];
    memset(vis,0,sizeof vis);
    for(int i=0;i<s.size();i++){
        if(vis[s[i]-'A']) continue;

        if(rec[s[i]]%2){ flag++; odd=s[i]; }
        else vec.PB(s[i]);

        vis[s[i]-'A']=1;
    }

    if(s.size()%2 && flag>1){ cout<<"NO SOLUTION"<<endl; return 0; }
    else if(s.size()%2==0 && flag){ cout<<"NO SOLUTION"<<endl; return 0; }

    for(int i=0;i<vec.size();i++)
        for(int j=0;j<rec[vec[i]]/2 ;j++) cout<<vec[i];

    if(odd!='0')
        for(int i=0;i<rec[odd];i++) cout<<odd;

    for(int i=vec.size()-1 ;i>=0;i--)
        for(int j=0;j<rec[vec[i]]/2 ;j++) cout<<vec[i];

    cout<<endl;
}
