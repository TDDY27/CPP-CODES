#include <bits/stdc++.h>

using namespace std;

int vis[10][10];
string s;

int dfs(int x,int y,int now){
    int ans=0;
    if(x==7 && y==1 && now==48) return 1;
    if(x==7 && y==1 && now!=48) return 0;
    if(x>7 || x<1 || y>7 || y<1 || now>48 || vis[x][y]) return 0;

    /*if(!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1]) return 0;
    if(vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1]) return 0;*/

    vis[x][y]=1;
    if(s[now]=='?'){
        ans+=dfs(x+1,y,now+1);
        ans+=dfs(x,y+1,now+1);
        ans+=dfs(x-1,y,now+1);
        ans+=dfs(x,y-1,now+1);
    }else if(s[now]=='D'){
        ans+=dfs(x+1,y,now+1);
    }else if(s[now]=='U'){
        ans+=dfs(x-1,y,now+1);
    }else if(s[now]=='L'){
        ans+=dfs(x,y-1,now+1);
    }else if(s[now]=='R'){
        ans+=dfs(x,y+1,now+1);
    }
    vis[x][y]=0;
    return ans;
}

signed main(){
    cin>>s;
    /*for(int i = 1; i <= 7; i++){
        vis[0][i] = 1;
        vis[i][0] = 1;
        vis[8][i] = 1;
        vis[i][8] = 1;
    }*/
    cout<<dfs(1,1,0)<<endl;
}
