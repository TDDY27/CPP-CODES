#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;


signed main(){
    int t;
    cin>>t;
    while(t>0){
        int a,b;
        cin>>a>>b;
        if(b>a) swap(a,b);

        int tmp=b+b-a;
        if(tmp%3==0 && b>=tmp && tmp>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        t--;
    }
}
