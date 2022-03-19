#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int t,n,u,v;
int const maxn=1e5+500;
vector <int> G[maxn];
int vis[maxn];
int rec[maxn];

int dfs(int a){
    int ans=1;
    vis[a]=1;
    for(int i:G[a]){
        if(vis[i]==0) ans+=dfs(i);
    }
    rec[a]=ans;
    return ans;
}

int cen[maxn];
void srch(int a){
    vis[a]=1;
    int flag=1;
    int same=-1;
    for(int i:G[a]){
        if(vis[i]==0 && rec[i]>n/2){
            flag=0;
            srch(i);
        }
        if(rec[i]==n-rec[i]) same=i;
    }
    if(flag==1) cen[a]=1;
    if(same!=-1) cen[same]=1;
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i=0;i<maxn;i++) G[i].clear();
        memset(vis,0,sizeof(vis));
        memset(rec,0,sizeof(rec));
        memset(cen,0,sizeof(cen));

        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
        }

        dfs(0);
        //for(int i=0;i<=n-1;i++) cout<<rec[i]<<" ";
        //cout<<endl;

        memset(vis,0,sizeof(vis));
        srch(0);
        for(int i=0;i<=n-1;i++){
            if(cen[i]==1){
                cout<<i<<endl;
                break;
            }
        }
        t--;
    }

}
