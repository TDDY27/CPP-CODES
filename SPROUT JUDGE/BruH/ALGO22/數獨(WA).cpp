#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int t;
string s;
int G[15][15];
int row[15][15];
int col[15][15];
int blo[15][15];

int next(int a,int b){
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if(G[i][j]==0 && i*100+j>a*100+b) return i*100+j;
	return -1;
}


int flag=0;
void dfs(int a,int b){
	int temp[15];
	memset(temp,0,sizeof(temp));
	for(int i=1;i<=9;i++) if(row[a][i]==1) temp[i]=1;
	for(int i=1;i<=9;i++) if(col[b][i]==1) temp[i]=1;
	for(int i=1;i<=9;i++) if(blo[ (b-1)/3+1 + ((a-1)/3)*3 ][i]==1) temp[i]=1;
	
	if(next(a,b)==-1){
		for(int i=1;i<=9;i++){
			if(temp[i]==0){
				G[a][b]=i;
				flag=1;
				return;
			}
		}
	}
	int x,y;
	x=next(a,b)/100; 
	y=next(a,b)%100;
	
	cout<<x<<" "<<y<<endl;
	for(int i=1;i<=9;i++) cout<<temp[i]<<" ";
	cout<<endl;
	for(int i=1;i<=9;i++){
		if(temp[i]==0){
			cout<<i<<endl;
			G[a][b]=i;
			row[a][i]=1;
			col[b][i]=1;
			blo[ (b-1)/3+1 + ((a-1)/3)*3 ][i]=1;
			dfs(x,y);
			if(flag) return;
		}
	}
}


signed main(){
	TDDY
	cin>>t;
	while(t>0){
		memset(G,0,sizeof(G));
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(blo,0,sizeof(blo));

		cin>>s;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(s[ i*9+j ]=='.' )
					G[i+1][j+1]=0;
				else
					G[i+1][j+1]=s[ i*9+j ]-'0';
			}
		}
		int sa,sb;
		sa=next(0,0)/100;
		sb=next(0,0)%100;
		
		flag=0;
		dfs(sa,sb);
		if(flag==0){
			cout<<"No solution."<<endl;
		//	t--;
		//	continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++)
				cout<<G[i][j]<<" ";
			cout<<endl;
		}
		//cout<<endl;
		t--;
	}
}
