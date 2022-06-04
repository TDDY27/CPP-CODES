#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);
#define int long long
#define PB push_back
#define w first
#define v second
#define pii pair<int,int>
#define INF 9e17

using namespace std;

int n,m;
int const maxn=2e5+500;
vector <pii> G[maxn];

priority_queue< pii, vector<pii>, greater<pii> > pq;
bool vis[maxn];

int Prim(){
    memset(vis,0,sizeof vis);

    pq.push({0,1});
    int ans=0;
    pii now;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(vis[now.v]) continue;
        vis[now.v]=1;
        ans+=now.w;
        pii mmin; mmin.w=INF;
        for(pii i:G[now.v])
            if(!vis[i.v] ){ mmin=i; pq.push(mmin); }
    }
    return ans;
}

signed main(){
    TDDY
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int tu,tv,tw;
        cin>>tu>>tv>>tw;
        G[tu].PB({tw,tv});
        G[tv].PB({tw,tu});
    }

    cout<<Prim()<<endl;
}
