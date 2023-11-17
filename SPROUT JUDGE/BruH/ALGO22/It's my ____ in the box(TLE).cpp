#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int t,n,m,x,y,q,ans;
int const maxn=1e5+500;
vector <int> v[maxn];
int rec[maxn];
int vis[maxn];

void dfs(int a){
    vis[maxn]=1;
    for(int i:v[a]){
        if(vis[i]==0){
            ans++;
            dfs(i);
        }else{
            ans+=rec[i];
        }
    }
    rec[a]=ans;
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n>>m;
        for(int i=0;i<maxn;i++) v[i].clear();
        fill(rec,rec+maxn,0);
        fill(vis,vis+maxn,0);
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].PB(y);
        }
        cin>>q;
        for(int i=0;i<q;i++){
            ans=0;
            cin>>x;
            if(vis[x]==0) dfs(x);
            cout<<rec[x]+1<<endl;
        }

        t--;
    }
}
