#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int const maxn=150;
int t,n,m,kx,ky;
int G[maxn][maxn];

struct info{
	int x;
	int y;
	int ths;
	int lst;
};

signed main(){
	TDDY
	cin>>t;
	while(t>0){
		memset(G,0,sizeof(G));
		cin>>n>>m;
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='#') G[i][j+1]=0;
				else if(s[j]=='K'){ kx=i;ky=j+1; G[i][j+1]=0;}
				else if(s[j]=='@')G[i][j+1]=3;
				else if(s[j]=='.')G[i][j+1]=1;
			}
		}

		info now;
		now.x=kx;
		now.y=ky;
		now.lst=0;
		now.ths=0;
		queue <info> q;
		q.push(now);

		int flag=-1;
		info temp;
		while(q.size()!=0){
			now=q.front();
			q.pop();
			if(G[now.x][now.y+1]==1 || G[now.x][now.y+1]==3){
				if(G[now.x][now.y+1]==3){
					flag=now.ths+1;
					break;
				}
				G[now.x][now.y+1]=0;
				temp=now;
				temp.y++;
				temp.lst=now.ths;
				temp.ths=now.ths+1;
				q.push(temp);
			}
			if(G[now.x][now.y-1]==1 || G[now.x][now.y-1]==3){
				if(G[now.x][now.y-1]==3){
					flag=now.ths+1;
					break;
				}
				G[now.x][now.y-1]=0;
				temp=now;
				temp.y--;
				temp.lst=now.ths;
				temp.ths=now.ths+1;
				q.push(temp);
			}
			if(G[now.x+1][now.y]==1|| G[now.x+1][now.y]==3){
				if(G[now.x+1][now.y]==3){
					flag=now.ths+1;
					break;
				}
				G[now.x+1][now.y]=0;
				temp=now;
				temp.x++;
				temp.lst=now.ths;
				temp.ths=now.ths+1;
				q.push(temp);
			}
			if(G[now.x-1][now.y]==1|| G[now.x-1][now.y]==3){
				if(G[now.x-1][now.y]==3){
					flag=now.ths+1;
					break;
				}
				G[now.x-1][now.y]=0;
				temp=now;
				temp.x--;
				temp.lst=now.ths;
				temp.ths=now.ths+1;
				q.push(temp);
			}
		}

		if(flag==-1) cout<<"= =\""<<endl;
		else cout<<flag<<endl;
		t--;
	}
}
