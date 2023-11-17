#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PB push_back

using namespace std;

int t,n,m;
int const maxn=1e5+500;
vector <int> G[maxn];
int rec[maxn];

priority_queue < int, vector<int>, greater<int> > pq;
queue <int> ans;

void topo(){
    while(!pq.empty()) pq.pop();
    while(!ans.empty()) ans.pop();

    for(int i=0;i<n;i++)
        if(rec[i]==0){ pq.push(i); rec[i]--; }

    int now;
    while(!pq.empty()){
        now=pq.top(); pq.pop(); ans.push(now);

        for(int i:G[now]){
            rec[i]--;
            if(rec[i]==0 ){ pq.push(i); rec[i]--; }
        }
    }
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        for(int i=0;i<maxn;i++) G[i].clear();
        memset(rec,0,sizeof rec);

        cin>>n>>m;
        for(int i=0;i<m;i++){
            int tu,tv;
            cin>>tu>>tv;
            G[tu].PB(tv);
            rec[tv]++;
        }

        topo();
        if(ans.size()<n) cout<<"QAQ"<<endl;
        else{
            cout<<ans.front(); ans.pop();
            while(!ans.empty()){
                cout<<" "<<ans.front();
                ans.pop();
            }
            cout<<endl;
        }

        t--;
    }
}
