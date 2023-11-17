#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PB push_back
#define int long long
#define INF 9e17 // long long can't more than 1e18
#define pii pair<int,int>
#define w first
#define v second

using namespace std;

int n,m,q;
int const maxn=2e5+500;
vector <pii> G[2][maxn];

int dis[2][maxn];
priority_queue < pii, vector<pii>, greater<pii> > pq;

void Dijkstra(int pos,int run){
    fill(dis[run],dis[run]+maxn,INF);
    while(!pq.empty()) pq.pop();

    dis[run][pos]=0;
    pq.push({0,pos});

    pii now;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(dis[run][now.v]<now.w) continue;
        for(pii i:G[run][now.v]){
            if(dis[run][i.v]>now.w+i.w){
                dis[run][i.v]=now.w+i.w;
                pq.push({now.w+i.w,i.v});
            }
        }
    }
}

signed main(){
    TDDY
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int tu,tv,tw;
        cin>>tu>>tv>>tw;
        G[0][tu].PB({tw,tv});
        G[1][tv].PB({tw,tu});
    }

    Dijkstra(1,0);
    Dijkstra(n,1);

    for(int i=0;i<q;i++){
        int c,d; cin>>c>>d;
        cout<< min( dis[0][n], dis[0][c]+dis[1][d]+1)<<endl;
    }
}
