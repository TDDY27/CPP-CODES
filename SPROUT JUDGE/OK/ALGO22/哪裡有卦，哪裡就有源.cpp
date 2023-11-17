#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int const maxn=1e5+500;
int t,n,m;
vector <int> G[maxn];
int clr[maxn];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n>>m;
        for(int i=0;i<maxn;i++) G[i].clear();
        memset(clr,0,sizeof(clr));

        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
        }

        int now=u;
        clr[now]=1;
        queue <int> q;
        q.push(now);

        int flag=1;
        while(q.size()>0){
            now=q.front();
            q.pop();
            //cout<<now<<" "<<clr[now]<<endl;
            for(int i:G[now]){
                if(clr[i]==clr[now]){
                    flag=0;
                    break;
                }else if(clr[i]==0){
                    clr[i]=clr[now]*-1;
                    q.push(i);
                }
            }
            if(flag==0) break;
        }

        if(flag==1) cout<<"NORMAL."<<endl;
        else cout<<"RAINBOW."<<endl;

        t--;
    }
}
