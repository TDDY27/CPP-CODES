#include <bits/stdc++.h>
#define int long long
using namespace std;

struct info{
    int v,p;
};

stack <info> stk;

signed main(){
    int n,x;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>x;
        while(stk.size()>0){
            if(stk.top().v>=x) stk.pop();
            else break;
        }
        if(stk.size()) cout<<stk.top().p<<" ";
        else cout<<0<<" ";
        info tmp;
        tmp.v=x, tmp.p=i;
        stk.push(tmp);
    }

}
