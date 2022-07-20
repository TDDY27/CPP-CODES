#include <bits/stdc++.h>
#define PB push_back
using namespace std;

vector<string> str;

signed main(){
    int t;
    cin>>t;

    str.PB("0"), str.PB("1");
    for(int i=2;i<( 1<<t );i<<=1){
        for(int j=i-1;j>=0;j--) str.PB(str[j]);

        for(int j=0;j<i;j++) str[j]="0"+str[j];
        for(int j=i;j<i*2;j++) str[j]="1"+str[j];
    }

    for(string s:str) cout<<s<<endl;
}
