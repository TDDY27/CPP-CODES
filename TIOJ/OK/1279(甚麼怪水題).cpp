#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int num;

signed main(){
    TDDY
    while(cin>>num){
        int bruh=num*100/101 -2;
        int ans=-1;
        for(int i=bruh;i<=num;i++)
            if( (100*i+i)-(num*100) <100 && (100*i+i)-(num*100) >=0 ){ ans=i; break;}
        if(ans>1024 || ans<0 ) cout<<"stupid"<<endl;
        else cout<<ans<<endl;
    }
}
