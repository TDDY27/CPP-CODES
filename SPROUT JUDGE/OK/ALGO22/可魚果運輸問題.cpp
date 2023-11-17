#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int,int>
#define INF 9e17
#define PB push_back
#define w first
#define v second

using namespace std;

int t,n,m,s,e,f;
vector <pii> G[150];
int dis[150];
priority_queue< pii, vector<pii>, greater<pii> > pq;

void Dijkstra(int pos){
    fill(dis,dis+150,INF);
    while(!pq.empty()) pq.pop();

    dis[pos]=0;
    pq.push({0,pos});
    pii now;
    while(!pq.empty()){
        now=pq.top();pq.pop();
        if(dis[now.v]<now.w) continue;
        for(pii i:G[now.v]){
            if(dis[i.v]>now.w+i.w){
                dis[i.v]=now.w+i.w;
                pq.push({dis[i.v],i.v});
            }
        }
    }

}

signed main(){
    TDDY

    cin>>t;
    while(t>0){
        for(int i=0;i<150;i++) G[i].clear();

        cin>>n>>m>>s>>e>>f;
        for(int i=0;i<m;i++){
            int tu,tv,tw1,am,tw2; // am=amount
            cin>>tu>>tv>>tw1>>am>>tw2;
            int pr=0;//price
            if(f>am) pr=(am*tw1)+(f*tw2-am*tw2);
            else pr=f*tw1;
            G[tu].PB({pr,tv});
        }

        Dijkstra(s);
        cout<<dis[e]<<endl;

        t--;
    }
}
