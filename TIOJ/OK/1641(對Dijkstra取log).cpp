#include <bits/stdc++.h>
#include <cmath>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define INF 9e17
#define pdi pair<double,int>
#define w first
#define v second
#define PB push_back

using namespace std;

int n,m,s,t;
int const maxn=1e4+500;
vector <pdi> G[maxn];

double dis[maxn];
priority_queue< pdi, vector<pdi>, greater<pdi> > pq;

void Dijkstra(int pos){
    fill(dis,dis+maxn,INF);

    dis[pos]=0;
    pq.push({0,pos});

    pdi now;
    while(!pq.empty()){
        now=pq.top(); pq.pop();
        if(dis[now.v]<now.w) continue;
        for(pdi i:G[now.v]){
            if(dis[i.v]>now.w+i.w){
                dis[i.v]=now.w+i.w;
                pq.push({dis[i.v],i.v});
            }
        }
    }
}

signed main(){
    TDDY
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int tu,tv; double tw;
        cin>>tu>>tv>>tw;
        tw=log10(tw+1);
        G[tu].PB({tw,tv});
    }

    Dijkstra(s);

    int exp=dis[t];
    double ans=pow(10,dis[t]-exp);
    cout<<fixed<<setprecision(2)<<ans<<"e";

    cout<<"+";
    for(int i=100;i>=1;i/=10){
        if(exp>=i){ cout<<exp<<endl; break;}
        cout<<0;
    }
}
