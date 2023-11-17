#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int t,n,m,x,y,q;
int const maxn=1e5+500;
vector <int> v[maxn];
int rec[maxn];
int nd[maxn];//need dfs

int dfs(int a){
    int ans=1;
    for(int i:v[a]){
        ans+=dfs(i);
    }
    rec[a]+=ans;
    return ans;
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n>>m;
        for(int i=0;i<maxn;i++) v[i].clear();
        fill(rec,rec+maxn,0);
        fill(nd,nd+maxn,1);
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].PB(y);
            nd[y]=0;
        }
        for(int i=0;i<maxn;i++){
            if(nd[i]==1) dfs(i);
        }
        cin>>q;
        for(int i=0;i<q;i++){
            cin>>x;
            cout<<rec[x]<<endl;
        }
        t--;
    }
}
