#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int t;
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
        flag=1;
        return;
    }
    int temp[15];
    memset(temp,0,sizeof(temp));
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
			if(flag) return;
		}
	}
	G[a][b]=0;
}

int check(){
    int temp[15];

    for(int i=1;i<=9;i++){
        memset(temp,0,sizeof(temp));
        for(int j=1;j<=9;j++){
            if(temp[G[i][j]]==1) return -1;
            temp[G[i][j]]=1;
        }
    }

    for(int i=1;i<=9;i++){
        memset(temp,0,sizeof(temp));
        for(int j=1;j<=9;j++){
            if(temp[G[j][i]]==1) return -1;
            temp[G[j][i]]=1;
        }
    }

    for(int i=1;i<=7;i+=3){
        for(int j=1;j<=7;j+=3){
            memset(temp,0,sizeof(temp));
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(temp[G[k][l]]==1) return -1;
                    temp[G[k][l]]=1;
                }
            }
        }
    }

    return 1;
}

signed main(){
	TDDY
	cin>>t;
	while(t>0){
		memset(G,0,sizeof(G));

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
		int ch=check();
		if(flag==0 || ch==-1){
			cout<<"No solution."<<endl;
			t--;
			continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++)
				cout<<G[i][j];//<<" ";
			//cout<<endl;
		}
		cout<<endl;
		t--;
	}
}
