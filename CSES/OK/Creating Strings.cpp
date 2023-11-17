#include <bits/stdc++.h>
#define TDDY ::ios_base::sycn_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int rec[28];
vector <string> str;

signed main(){
    string s;
    cin>>s;
    for(char ch:s) rec[ch-'a']++;
    s.clear();
    for(int i=0;i<26;i++){
        for(int j=0;j<rec[i];j++) s+='a'+i;
    }

    str.PB(s);
    while( next_permutation(s.begin(),s.end()) ) str.PB(s);

    cout<<str.size()<<endl;
    for(int i=0;i<str.size();i++) cout<<str[i]<<endl;

}
