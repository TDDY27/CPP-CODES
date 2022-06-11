#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int,int>
#define w first
#define v second
#define INF 9e17
#define PB push_back

int n,m,a,b;
int const maxn=1e6+500;
vector <pii> G[maxn];

priority_queue<pii, vector<pii>, greater<pii> > pq;
int dis[2][maxn];

void Dijkstra(int a){
    fill(dis[0],dis[0]+maxn,INF);

    dis[0][a]=0. dis[1][a]=-1;
    pq.push({0,a});
    pii now;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(dis[0][now.v]<now.w) continue;
        for(pii i:G[now.v]){
            if(dis[0][i.v]>dis[0][now.v]+i.w){
                dis[i.v]=dis[now.v]+i.w;
                pq.push({ dis[i.v], i.v });
                dis[1][i.v]=now.v;
            }
        }
    }
}


signed main(){
    cin>>n>>m>>a>>b;
    for(int i=0;i<m;i++){
        int tu,tv;
        cin>>tu>>tv;
        G[tu].PB({1,tv});
        G[tv].PB({1,tu});
    }

}
