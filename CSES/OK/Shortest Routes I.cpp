#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define w first
#define v second
#define PB push_back
#define INF 9e15
#define int long long
#define pii pair<int,int>
using namespace std;

int n,m;
int const maxn=1e5+500;
vector <pii> G[maxn];

int dis[maxn];
priority_queue< pii, vector<pii> ,greater<pii> > pq;

void Dijkstra(){
    fill(dis, dis+maxn, INF);
    dis[1]=0;
    pq.push({0,1});

    pii now;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(dis[now.v]<now.w) continue;//has relaxed 
        for(pii i:G[now.v]){
            if(dis[i.v]>now.w+i.w){
                dis[i.v]=now.w+i.w;
                pq.push({now.w+i.w,i.v});
            }
        }
    }

}

signed main(){
    TDDY
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int tu,tv,tw;
        cin>>tu>>tv>>tw;
        G[tu].PB({tw,tv});
    }

    Dijkstra();
    for(int i=1;i<=n;i++) cout<<dis[i]<<" \n"[i==n];
}
