#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int t,n;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        stack <int> stk;
        cin>>n;

        int now=9;
        while(now>0){
            if(n%now==0){
                //cout<<now<<endl;
                stk.push(now);
                n/=now;
                if(now!=1)continue;
            }
            now--;
        }
        if(n>1) cout<<-1<<endl;
        else{
            if(stk.size()>1) stk.pop();
            while(stk.size()>0){
                cout<<stk.top();
                stk.pop();
            }
            cout<<endl;
        }

        t--;
    }
}
