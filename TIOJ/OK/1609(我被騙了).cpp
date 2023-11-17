#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

signed main(){
    TDDY
    cin>>n;
    for(int i=0;i<n;i++){ int tmp; cin>>tmp, pq.push(tmp); }
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop();}
}
