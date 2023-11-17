#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

struct info{
    int u;
    int v;
    int w;
};

bool cmp(info a,info b){ return a.w>b.w; }

int n,m;
int const maxn=2e5+500;
vector <info> edg;
int dsu[maxn];

int fa(int a){
    if(dsu[a]==a) return a;
    return dsu[a]=fa(dsu[a]);
}

void join(int a,int b){
    dsu[fa(b)]=fa(a);
}

int kruskal(){
    int ans=0;
    info now;
    while(!edg.empty()){
        now=edg.back(); edg.pop_back();
        if( fa(now.u)!=fa(now.v) ){
            ans+=now.w;
            join(now.u,now.v);
        }
    }
    return ans;
}

signed main(){
    TDDY
    cin>>n>>m;
    for(int i=0;i<m;i++){
        info tmp;
        cin>>tmp.u>>tmp.v>>tmp.w;
        edg.PB(tmp);
    }

    sort(edg.begin(),edg.end(),cmp);
    for(int i=0;i<maxn;i++) dsu[i]=i;
    cout<<kruskal()<<endl;
}

