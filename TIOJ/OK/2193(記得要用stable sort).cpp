#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define ind first
#define pos second
using namespace std;

int n;
pii num[1500];

int one(int a){
    int sum=0;
    for(int i=1;i<=a;i<<=1)
        if(i&a) sum++;
    return sum;
}

bool cmp(pii a,pii b){
    if(one(a.ind)!=one(b.ind)) return one(a.ind)<one(b.ind);
    return a.pos<b.pos;
}

signed main(){
    TDDY
    while(cin>>n){
        memset(num,0,sizeof num);
        for(int i=0;i<n;i++){ cin>>num[i].ind; num[i].pos=i; }
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++) cout<<num[i].ind<<" \n"[i==n-1];
    }
}
