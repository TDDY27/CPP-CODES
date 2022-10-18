#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

priority_queue< pii, vector<pii>, greater<pii> >pq;

signed main(){
    int n,a,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>d;
        pq.push({a,d});
    }
    int now=0,ans=0,tmpa,tmpd;
    for(int i=0;i<n;i++){
        tmpa=pq.top().ff;
        tmpd=pq.top().ss;
        now+=tmpa;
        ans+=(tmpd-now);
        pq.pop();
    }
    cout<<ans<<endl;
}
