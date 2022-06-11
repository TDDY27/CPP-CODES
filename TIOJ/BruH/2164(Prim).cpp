#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
#define pii pair<int,int>
#define w first
#define v second

using namespace std;

struct pos{
    int x;
    int y;
    int z;
};

int dis(pos a, pos b){
    int x1=a.x-b.x, y1=a.y-b.y, z1=a.z-b.z;
    return x1*x1+y1*y1+z1*z1;
}

int const maxn=5500;
int n;
vector <pos> rec;
vector <pii> G[maxn];

priority_queue < pii, vector<pii>, greater<pii> > pq;
int vis[maxn];
int Prim(){
    memset(vis,0,sizeof vis);

    pq.push({0,1});
    pii now;
    int ans=0;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(vis[now.v]) continue;
        ans+=now.w;
        vis[now.v]=1;

        for(pii i:G[now.v])
            if(!vis[i.v]) pq.push(i);
    }
    return ans;
}

signed main(){
    TDDY
    cin>>n;
    for(int i=0;i<n;i++){
        pos tmp;
        cin>>tmp.x>>tmp.y>>tmp.z;
        rec.PB(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tmp=dis(rec[i],rec[j]);
            G[i+1].PB({ tmp, j+1 }) ;
            G[j+1].PB({ tmp, i+1 }) ;
        }
    }
    cout<<Prim()<<endl;
}
