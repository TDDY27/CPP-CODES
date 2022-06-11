#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
#define pii pair<int,int>
#define w first
#define v second
#define INF 9e17

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

int const maxn=5050;
int n;
pos rec[maxn];
int G[maxn][maxn]; // because of the dense graph

int Prim(){
    int dis[maxn], vis[maxn];
    fill(dis,dis+maxn,INF);
    memset(vis,0,sizeof vis);
    int ans=0, now=1, next;
    dis[1]=0;

    for(int t=0;t<n;t++){
        ans+=dis[now];
        vis[now]=1;
        int mmin=INF;

        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            dis[i]=min(dis[i],G[now][i]);
            if(dis[i]<mmin){ mmin=dis[i]; next=i; }
        }
        now=next;
    }
    return ans;
}

signed main(){
    TDDY
    cin>>n;
    for(int i=1;i<=n;i++) cin>>rec[i].x>>rec[i].y>>rec[i].z;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            G[i][j]=G[j][i]=dis(rec[i],rec[j]);

    cout<<Prim()<<endl;
}
