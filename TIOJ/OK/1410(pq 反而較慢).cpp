#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

struct info{
    int tm;
    int go;
};

struct cmp{
    //priority queue 會優先判定為!cmp 所以要反向來做
    bool operator()(info a,info b){
        if(a.tm!=b.tm) return a.tm>b.tm;
        else return a.go<b.go;
    }
};


int n;
priority_queue<info, vector<info>, cmp>pq;

signed main(){
    TDDY

    cin>>n;
    for(int i=0;i<n;i++){
        info tmp;
        cin>>tmp.tm; tmp.go=1, pq.push(tmp);
        cin>>tmp.tm; tmp.go=-1, pq.push(tmp);
    }

    int ans=0,rec=0;
    info now;
    while(!pq.empty()){
        now=pq.top(), pq.pop();
        ans=max(ans,rec+now.go);
        rec+=now.go;
    }
    cout<<ans<<endl;
}
