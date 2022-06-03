#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int n,e;
string who;
int const maxn=1e4+500;
vector <int> G[maxn];
int rec[maxn];

queue<int> que;
int res[maxn];

void topo(){
    while(!que.empty()) que.pop();
    memset(res,0,sizeof res);

    res[n]=2;
    que.push(n);
    int now;
    while(!que.empty()){
        now=que.front(); que.pop();
        for(int i:G[now]){
            rec[i]--;
            if(res[now]==2) res[i]=1; // must win
            if(rec[i]==0){
                if(res[now]==1 && res[i]==0) res[i]=2;
                rec[i]--; que.push(i);
            }
        }
    }
}

signed main(){
    TDDY
    while(cin>>n>>e && (n||e) ){
        for(int i=0;i<maxn;i++) G[i].clear();
        memset(rec,0,sizeof rec);

        for(int i=0;i<e;i++){
            int tu,tv;
            cin>>tu>>tv;
            if(tu==n) continue;
            G[tv].PB(tu);// reverse topo
            rec[tu]++;
        }

        topo();
        cin>>who;
        if(res[1]==2) cout<<who<<endl;
        else{
            if(who[1]=='i') cout<<"Moumou"<<endl;
            else cout<<"Mimi"<<endl;
        }

    }
}

