#include <bits/stdc++.h>
//#define TDDY ::ios_base::sync_with_stdio(false);cout.tie(0);
using namespace std;

int N;
int const maxn=1e5+500;
int a[maxn];

void solve(int n){
    if(n==3){
        a[1]=3;
        a[2]=1;
        a[3]=2;
        return ;
    }else if(n==2){
        a[1]=2;
        a[2]=1;
        return ;
    }else if(n==1){
        a[1]=1;
        return;
    }

    solve((n+1)/2);
    int now=1;
    for(int i=1;i<=(n+1)/2;i++)
        a[now++]=(a[i]*2-1);
    for(int i=1;i<=(n+1)/2;i++)
        if(a[i]+1<=n) a[now++]=(a[i]+1);
    return ;
}

signed main(){
    //TDDY
    cin>>N;
    solve(N);
    cout<<a[1];
    for(int i=2;i<=N;i++) cout<<" "<<a[i];
    cout<<endl;
}
