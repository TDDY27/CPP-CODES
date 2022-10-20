#include <bits/stdc++.h>
#define int long long

using namespace std;

struct info{
    int p1,p2;
};

map <int,info> mp;
int num[2000];

signed main(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>num[i];

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            info tmp;
            tmp.p1=i, tmp.p2=j;
            mp.insert({x-num[i]-num[j], tmp});
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mp.count(num[i]+num[j])){
                info tmp=mp[num[i]+num[j]];
                if(tmp.p1==i || tmp.p1==j || tmp.p2==i || tmp.p2==j) continue;
                cout<<i<<" "<<j<<" "<<tmp.p1<<" "<<tmp.p2<<"\n";
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<"\n";
}
