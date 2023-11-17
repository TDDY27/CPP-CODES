#include <bits/stdc++.h>
#define int long long

using namespace std;

int G[10][10];

void upd(int x,int y,int val){
    for(int i=1;i<=8;i++) G[x][i]+=val, G[i][y]+=val;
    for(int i=1;i<=8;i++){
        if(x+i>8 || y+i>8) break;
        G[x+i][y+i]+=val;
    }
    for(int i=1;i<=8;i++){
        if(x+i>8 || y-i<1) break;
        G[x+i][y-i]+=val;
    }
    for(int i=1;i<=8;i++){
        if(x-i<1 || y-i<1) break;
        G[x-i][y-i]+=val;
    }
    for(int i=1;i<=8;i++){
        if(x-i<1 || y+i>8) break;
        G[x-i][y+i]+=val;
    }
}

int  solve(int n){
    int ans=0;
    if(!n) return 1;
    for(int i=1;i<=8;i++){
        if(G[n][i]) continue;
        upd(n,i,1);
        ans+=solve(n-1);
        upd(n,i,-1);
    }

    return ans;
}

signed main(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            char tmp;
            cin>>tmp;
            if(tmp=='*') G[i][j]=1;
        }
    }

    cout<<solve(8)<<endl;
}
