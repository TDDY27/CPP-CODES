#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define INF 9e19
#define PB push_back
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n;
vector< pii > pos;

int dis(pii a,pii b){
    int x2,y2;
    x2=(a.x-b.x)*(a.x-b.x);
    y2=(a.y-b.y)*(a.y-b.y);
    return x2+y2;
}

int solve(int l,int r){
    if(l>=r) return INF;
    int mid=(l+r)/2 , midx=pos[mid].x;
    int ans=min(solve(l,mid) , solve(mid+1,r));

    vector<pii> tmpos; //merge two arrange and sort by y
    tmpos.clear();
    int tmp1=l,tmp2=mid+1;
    while(tmp1<=mid || tmp2<=r){
        if( (pos[tmp1].y<=pos[tmp2].y && tmp1<=mid) || tmp2>r) tmpos.PB(pos[tmp1++]);
        else tmpos.PB(pos[tmp2++]);
    }

    for(int i=0;i<r-l+1;i++) pos[l+i]=tmpos[i];

    tmpos.clear();
    for(int i=l;i<=r;i++)
        if( (pos[i].x-midx)*(pos[i].x-midx) <ans ) tmpos.PB(pos[i]);

    for(int i=0;i<tmpos.size();i++){
        for(int j=i+1;j<tmpos.size();j++){
            if( (tmpos[j].y-tmpos[i].y)*(tmpos[j].y-tmpos[i].y) >=ans) break;
            ans=min(ans, dis(tmpos[i],tmpos[j]));
        }
    }

    return ans;
}

signed main(){
    TDDY
    cin>>n;
    for(int i=0;i<n;i++){
        int tmpx,tmpy;
        cin>>tmpx>>tmpy;
        pos.PB({tmpx,tmpy});
    }

    sort(pos.begin() ,pos.end());
    int res;
    res=solve(0,n-1);
    cout<<res<<endl;
    /*for(int i=0;i<n;i++) cout<<pos[i].y<<" ";
    cout<<endl;*/
}
