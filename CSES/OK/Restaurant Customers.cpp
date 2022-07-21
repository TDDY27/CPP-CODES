#include <bits/stdc++.h>

using namespace std;

struct info{
    int io; //in out
    int t; // time
};

int const maxn=2e5+500;
info cus[maxn*2];

bool cmp(info a,info b){ return a.t<b.t; }

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n*2;i+=2){
        cin>>cus[i].t;
        cus[i].io=1;
        cin>>cus[i+1].t;
        cus[i+1].io=-1;
    }

    sort(cus,cus+2*n,cmp);
    int mmax=-1,now=0;
    for(int i=0;i<n*2;i++){
        now+=cus[i].io;
        mmax=max(mmax,now);
    }

    cout<<mmax<<endl;
}
