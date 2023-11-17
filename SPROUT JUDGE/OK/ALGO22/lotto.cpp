#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int t,k,l;
int num[20];

int rec[15];
void dfs(int ind,int depth){
	rec[depth]=num[ind];
	if(depth==6){
		cout<<rec[1];
		for(int i=2;i<=6;i++) cout<<" "<<rec[i];
		cout<<endl;
	}else if(depth<6){
		for(int i=ind+1;i<k;i++) dfs(i,depth+1);
	}		
}

signed main(){
	TDDY
	cin>>t;
	while(t>0){
		cin>>k;
		fill(num,num+20,2147483647);	
		fill(rec,rec+15,0);

		for(int i=0;i<k;i++) cin>>num[i];
		sort(num,num+20);
		//for(int i=0;i<k;i++) cout<<num[i];
		for(int i=0;i<k-5;i++) dfs(i,1);
		t--;
	}

}
