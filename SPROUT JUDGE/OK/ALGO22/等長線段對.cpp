#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int,int>
using namespace std;

struct info{
    int x;
    int y;
};

int n;
info G[1500];

int dis(info a,info b){
    int x1=a.x-b.x, y1=a.y-b.y;
    return x1*x1+y1*y1;
}

unordered_map <int,int> rec;

signed main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>G[i].x>>G[i].y;

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int tmp=dis(G[i],G[j]);
            if(!rec.count(tmp)) rec.insert( pii(tmp,1));
            else{ ans+=rec[tmp]; rec[tmp]++; }
        }
    }
    cout<<ans<<endl;
}
