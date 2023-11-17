#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

struct info{
    int ar,dp,ind;
};

int const maxn=2e5+500;
int rm[maxn];
info day[maxn];
priority_queue<pii, vector<pii>, greater<pii> > pq;

bool cmp(info a,info b){
    if(a.ar!=b.ar) return a.ar<b.ar;
    return a.dp<b.dp;
}

signed main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        day[i].ar=a, day[i].dp=b, day[i].ind=i;
    }
    sort(day,day+n,cmp);

    int k=1;
    pq.push({day[0].dp,1});
    rm[day[0].ind]=1;
    for(int i=1;i<n;i++){
        if(day[i].ar<=pq.top().ff){
            rm[day[i].ind]=++k;
            pq.push({day[i].dp,k});
        }else{
            rm[day[i].ind]=pq.top().ss;
            pq.push({day[i].dp, pq.top().ss});
            pq.pop();
        }
    }
    cout<<k<<"\n";
    for(int i=0;i<n;i++)
        cout<<rm[i]<<" ";
}
