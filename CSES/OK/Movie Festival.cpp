#include <bits/stdc++.h>

using namespace std;

struct info{
    int op;
    int ed;
};

int const maxn=2e5+500;
info mov[maxn];

bool cmp(info a,info b){
    if(a.ed!=b.ed) return a.ed<b.ed;
    else return a.op<b.op;
}

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>mov[i].op>>mov[i].ed;

    sort(mov,mov+n,cmp);
    int l=0,ans=0;
    for(int i=0;i<n;i++){
        if(mov[i].op>=l){
            ans++;
            l=mov[i].ed;
        }
    }
    cout<<ans<<endl;
}
