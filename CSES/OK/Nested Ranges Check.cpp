#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define PB push_back

using namespace std;

struct info{
    int l,r,ind;
};

int const maxn=2e5+500;
info R[maxn];
int bit[maxn], ans[maxn];
vector <pii> X,Y;

bool cmp(info a,info b){
    if(a.l!=b.l) return a.l<b.l;
    return a.r>b.r;
}

void update (int p){
    for( ; p<maxn; p+=p&-p ) bit[p]++;
}

int query(int p){
    int sum=0;
    for( ; p>0; p-=p&-p ) sum+=bit[p];
    return sum;
}

signed main(){
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        X.PB({x,i});
        Y.PB({y,i});
        R[i].ind=i;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int cnt=0,lst=0;
    for(pii p:X){
        if(p.ff!=lst) cnt++;
        R[p.ss].l=cnt;
        lst=p.ff;
    }

    cnt=lst=0;
    for(pii p:Y){
        if(p.ff!=lst) cnt++;
        R[p.ss].r=cnt;
        lst=p.ff;
    }

    sort(R, R+n, cmp);
    for(int i=n-1; i>=0; i--){
        ans[R[i].ind]=query(R[i].r);
        update(R[i].r);
    }
    for(int i=0;i<n;i++){
        cout<<!!ans[i]<<" ";
        ans[i]=0;
    }
    cout<<"\n";
    memset(bit,0,sizeof bit);

    for(int i=0;i<n;i++){
        ans[R[i].ind]=query(maxn-1)-query(R[i].r-1);
        update(R[i].r);
    }
    for(int i=0;i<n;i++)
        cout<<!!ans[i]<<" ";

}


// reference from thanksone





