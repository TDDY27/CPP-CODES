#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
#define INF 8e18
using namespace std;

struct pnt{
    int x;
    int y;
};

int n;
int const maxn=2e5+500;
pnt cod[maxn]; //coordinate

bool cmpx(pnt a,pnt b){ return a.x<b.x; }

int Dist(pnt a,pnt b){
    int Dx,Dy;
    Dx=(a.x-b.x)*(a.x-b.x);
    Dy=(a.y-b.y)*(a.y-b.y);
    return Dx+Dy;
}

int solve(int l,int r){
    if(r<=l) return INF;

    int mid=(l+r)/2;
    int dlr=min(solve(l,mid) ,solve(mid+1,r));

    queue <pnt> tmp_q;
    int nowl=l,nowr=mid+1;
    for(int i=l;i<=r;i++){
        if( (cod[nowl].y<=cod[nowr].y || nowr>r) && nowl<=mid)
            tmp_q.push(cod[nowl++]);
        else
            tmp_q.push(cod[nowr++]);
    }

    for(int i=l;i<=r;i++){
        cod[i]=tmp_q.front();
        tmp_q.pop();
    }

    vector <pnt> tmp_v;
    for(int i=l;i<=r;i++)
        if(cod[i].x-cod[mid].x<dlr) tmp_v.PB(cod[i]);

    for(int i=0;i<tmp_v.size();i++){
        for(int j=i+1;j<tmp_v.size();j++){
            if( abs(tmp_v[i].y-tmp_v[j].y)>=dlr) break;
            dlr=min( dlr,Dist(tmp_v[i],tmp_v[j]) );
        }
    }
    return dlr;
}

signed main(){
    TDDY
    cin>>n;
    for(int i=0;i<n;i++) cin>>cod[i].x>>cod[i].y;
    sort(cod,cod+n,cmpx);

    int ans;
    ans=solve(0,n-1);
    cout<<ans<<endl;
}

/*
10
25280705 121178189
219147240 -570920213
-829849659 923854124
18428128 -781819137
-876779400 528386329
-780997681 387686853
-101900553 749998368
58277314 355353788
732128908 336416193
840698381 600685123
*/


