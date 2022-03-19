#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,h,w;
int const maxn=1e3+500;
int G[maxn][maxn];
int vis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int a,int b){
	vis[a][b]=1;
	for(int i=0;i<4;i++){
		if(vis[a+dx[i] ][b+dy[i] ]==0 && G[a+dx[i] ][b+dy[i] ]==1) dfs(a+dx[i],b+dy[i]);
	}
}


signed main(){
	TDDY
	cin>>t;
	while(t>0){
		cin>>h>>w;
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));

		string tmp;
		for(int i=1;i<=h;i++){
			cin>>tmp;
			for(int j=0;j<w;j++){
				if(tmp[j]=='#') G[i][j+1]=0;
				else G[i][j+1]=1;
			}
		}
		
		int ans=0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(G[i][j]==1 && vis[i][j]==0){
					ans++;
					dfs(i,j);
				}
			}
		}
		cout<<ans<<endl;

		t--;
	}		
}
