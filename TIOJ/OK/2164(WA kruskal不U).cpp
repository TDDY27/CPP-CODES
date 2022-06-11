#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

struct pos{
    int x;
    int y;
    int z;
};

struct edg{
    int u;
    int v;
    int w;
};

int dis(pos a, pos b){
    int x1=a.x-b.x, y1=a.y-b.y, z1=a.z-b.z;
    return x1*x1+y1*y1+z1*z1;
}

int n;
vector <pos> rec;
vector <edg> G;

int const maxn=5500;
int F[maxn];

bool cmp(edg a, edg b){
    return a.w>b.w;
}

int fa(int a){
    if(F[a]==a) return a;
    return F[a]=fa(F[a]);
}

void join(int a, int b){
    F[fa(b)]=F[fa(a)];
}

int ans=0;
void Kruskal(){
    edg now;
    while(!G.empty()){
        now=G.back(), G.pop_back();
        if(fa(now.u)==fa(now.v)) continue;
        ans+=now.w;
        join(now.u, now.v);
    }
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
            edg tmp;
            tmp.u=i+1, tmp.v=j+1, tmp.w=dis(rec[i],rec[j]);
            G.PB(tmp);
        }
    }

    for(int i=1;i<=n;i++) F[i]=i;
    sort(G.begin(),G.end(),cmp);
    Kruskal();
    cout<<ans<<endl;
}
