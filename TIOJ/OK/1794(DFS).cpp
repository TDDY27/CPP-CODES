#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,m;
int G[3500][3500];
int vis[3500][3500]; // 1 unvisited ; 0 visited;

int dx[]={0,1,-1,0}, dy[]={1,0,0,-1};
int rec=0;
int dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tmpx=x+dx[i], tmpy=y+dy[i];
        if( vis[tmpx][tmpy]==1 && G[tmpx][tmpy]==G[x][y] ){
            vis[tmpx][tmpy]=0;
            dfs(tmpx,tmpy), rec++;
        }
    }
    return rec;
}


signed main(){
    TDDY
    memset(G,0,sizeof G);
    memset(vis,0,sizeof vis);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) { cin>>G[i][j]; vis[i][j]=1;}

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vis[i][j]==1){ rec=0; ans=max(ans,dfs(i,j));}
    cout<<ans<<endl;
}
