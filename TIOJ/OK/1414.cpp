#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n,m;
int G1[150][150], G2[150][150], vis1[150][150], vis2[150][150];

int dx[]={0,0,1,1,1,-1,-1,-1}, dy[]={1,-1,1,-1,0,1,-1,0};
void dfs1(int x,int y){
    vis1[x][y]=0;
    for(int i=0;i<8;i++){
        int tmpx=x+dx[i], tmpy=y+dy[i];
        if(G1[tmpx][tmpy] && vis1[tmpx][tmpy]) dfs1(tmpx,tmpy);
    }
}

void dfs2(int x,int y){
    vis2[x][y]=0;
    for(int i=0;i<8;i++){
        int tmpx=x+dx[i], tmpy=y+dy[i];
        if(G2[tmpx][tmpy] && vis2[tmpx][tmpy]) dfs2(tmpx,tmpy);
    }
}

signed main(){
    TDDY
    while(cin>>n>>m){
        memset(G1,0,sizeof G1);
        memset(G2,0,sizeof G2);
        memset(vis1,0,sizeof vis1);
        memset(vis2,0,sizeof vis2);

        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                int tmp=s[j-1]-'0';
                if(tmp){ G1[i][j]=1; vis1[i][j]=1; }
                if(tmp==2){ G2[i][j]=1; vis2[i][j]=1; }
            }
        }

        int one=0, two=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(G1[i][j] && vis1[i][j]){ dfs1(i,j); one++; }
                if(G2[i][j] && vis2[i][j]){ dfs2(i,j); two++; }
            }
        }
        cout<<one<<" "<<two<<endl;
    }

}
