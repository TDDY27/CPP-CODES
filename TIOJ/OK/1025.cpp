#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int ans;
string s;
int G[15][15];

int next(int a,int b){
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if(G[i][j]==0 && i*100+j>a*100+b) return i*100+j;
	return -1;
}

int flag;
void dfs(int a,int b){
   if(a==0 && b==-1){
      for(int i=1;i<=9;i++){
    		for(int j=1;j<=9;j++)
		    		cout<<G[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
   	ans++;
		return;
	}
  int temp[15];
  memset(temp,0,sizeof(temp))
  for(int i=1;i<=9;i++) temp[G[i][b]]=1;
  for(int i=1;i<=9;i++) temp[G[a][i]]=1;
  for(int i=( (a-1)/3)*3+1;i<( (a-1)/3)*3+4;i++)
        for(int j=( (b-1)/3)*3+1;j<( (b-1)/3)*3+4;j++)
            temp[G[i][j]]=1;
	int x,y;
	x=next(a,b)/100;
	y=next(a,b)%100;

	for(int i=1;i<=9;i++){
		if(temp[i]==0){
			G[a][b]=i;
			dfs(x,y);
		}
	}
	G[a][b]=0;
}

signed main(){
	TDDY
	memset(G,0,sizeof(G));
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++) cin>>G[i][j];
			
	int sa,sb;
	sa=next(0,0)/100;
	sb=next(0,0)%100;

	dfs(sa,sb);
	cout<<"there are a total of "<<ans<<" solution(s).";
}
